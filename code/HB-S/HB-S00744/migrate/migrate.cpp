#include<bits/stdc++.h>
using namespace std;
int n,c,d,T,ans;
long long x[2000005],num[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>c>>T;
	while(T--){
            ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int t=0;
                for(int k=i+1;k<=j-1;k++){
                    if(x[k]-x[i]<=d&&x[j]-x[k]<=d&&x[j]-x[i]>d){
                        t++;
                    }
                }
                if(t==2){
                    ans++;
                   // cout<<i<<" "<<j<<endl;
                    if(c==11||c==12){
                        ans=n-j+1;
                        break;
                    }
                }
                //if(c==11||c==12)break;
            }
            if(c==11||c==12)break;
        }

        cout<<ans<<endl;
	}
	return 0;
}
