#include <bits/stdc++.h>
using namespace std;
const int MMax = 5e5+9;
int N;
long long M;
long long a[MMax],d[MMax];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    sort(a+1,a+N+1);

    for(int i=1;i<=N;i++){
        d[i] = d[i-1]+a[i];
    }

    int ans = -1,cnt;
    int i = 1,j=1;
    while(i<=j&&j<=N){
        cnt = (j-i)*a[j]-d[j]+d[i];
        if(cnt<=M){
            ans = max(ans,j-i);
            j++;

        }
        else{
            i++;
        }

    }
    cout << ans;
    return 0;
}
