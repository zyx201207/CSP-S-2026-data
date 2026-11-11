#include <iostream>
#define ll long long
using namespace std;
const int C=25+5,T=1e5+5,N=2e6+5,SN=2e6+5;
const ll D=2e18+5,X=1e18+5;
int c,t,n,is;
ll d,x[N],s[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		is=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=x[i]-x[i-1];
			if(i>2&&s[i]!=s[i-1])is=0;
		}
		s[1]=0;
		if(is){
			d=d/s[2];
			if(d<=1){
				cout<<0<<endl;
			}else{
				int l=d*2-1;
				if(l>n-1)cout<<0<<endl;
				else cout<<n-l<<endl;
			}
		}else{
			ans=0;
			for(int i=1,j=1,k=1;i<=n;i++,j=max(i,j),k=max(j,k)){
				while(x[j+1]-x[1]<=d)j+=1;
				while(x[k+1]-x[j]<=d)k+=1;
				if(x[k]-x[j-1]<=d&&x[k]-x[j-2]>d&&i<j-1&&j<k){
					ans+=1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

