#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

/*
5 3
31 3 1 15 7
*/

char arr[MAXN][35];
int Next[MAXN],tot[MAXN],Numb[MAXN];
int maxPos=0,k,First=1,ans;

void split(int id, int num){
    int ind = 0;
    while(num){
        tot[ind] += num & 1;
        arr[id][ind++] = num & 1;
        num >>= 1;
    }
    maxPos = max(maxPos,ind);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> Numb[i];
        split(i,Numb[i]);
    }
    for(int i = 2; i <= n+1; i++){
        Next[i-1] = i;
    }
    Next[n] = -1;
    for(int i = maxPos; i >= 0; i--){
        if(tot[i]>=m){
            int total = 0,j = First;
            while(j!=-1){
                if(arr[j][i]) total++;
                j = Next[j];
            }
            if(total < m) continue;
            int last = -1,cnt = 0;
            j = First;
            while(j!=-1){
                if(arr[j][i]) {
                    if(last == -1) {First = j; last = j; j = Next[j]; cnt++; continue;}
                    cnt++;
                    if(cnt == total) {Next[j]=-1;}
                    Next[last] = j;
                    last = j;
                }
                j = Next[j];
            }
        }
    }

    int j = First;
    ans = Numb[j];

    while(m--){
        ans &= Numb[j];
        //cout << Numb[j] << ' ' << j << endl;
        j = Next[j];
    }

    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
