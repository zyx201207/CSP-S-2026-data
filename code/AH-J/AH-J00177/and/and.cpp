#include <iostream>
#include <cmath>
using namespace std;
int n,k,d,s[200005],ans;
bool b[200005][35];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int cnt=0;
        cin >> d;
        while(d>0){
            b[i][++cnt]=d%2;
            d/=2;
        }s[i]=1;
    }for(int i=31;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(b[j][i]==1&&s[j]==1)cnt++;
            else s[j]=0;
        }if(cnt>=k)ans+=pow(2,i-1);
    }cout << ans;
    return 0;
}
