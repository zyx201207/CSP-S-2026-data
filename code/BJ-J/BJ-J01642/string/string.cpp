#include<bits/stdc++.h>
using namespace std;
char s[2000000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long idx=0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        char c;
        cin >> c;
        for(int j=1;j<=x;j++){
            s[++idx]=c;
        }
    }
    long long cnt=0;
    if(idx%2==1){
        long long i=1,j=idx;
        while(i<=(idx-1)/2&&j>=(idx-1)/2){
            if(s[i]!=s[j]){
                cnt++;
            }
            i++;
            j--;
        }
    }else{
        long long i=1,j=idx;
        while(i<=(idx/2)&&j>=(idx/2)){
            if(s[i]!=s[j]){
                cnt++;
            }
            i++;
            j--;
        }

    }
    cout << cnt << endl;
}
