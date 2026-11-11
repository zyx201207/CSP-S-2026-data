
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000010];
bool b[2000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,x=0;
        cin>>n>>d;
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                for(int k=1;k<=d+1;k++){
                    if(a[i+1]-a[i]<d&&a[i+2]-a[i]<d){
                        cnt++;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
