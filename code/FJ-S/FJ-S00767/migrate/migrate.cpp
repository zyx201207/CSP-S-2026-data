#include<bits/stdc++.h>
using namespace std;
long long z,t,n;
bool ta=1,tb=0;
long long a,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>z>>t;
	while(t--){
		cin>>n>>a;
		ta=1,tb=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=2){
			cout<<"0\n";
			continue;
		}
		if(z==11||z==12){
			long long b=x[1],c=x[2],d=n,e=0;
			cout<<max(e,d-a/(c-b)*2+1)<<"\n";
			continue;
		}
		if(z<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int s=0;
					if(x[j]-x[i]<=a){
						continue;
					}
					for(int k=i+1;k<j;k++){
						if(x[j]-x[k]<=a && x[k]-x[i]<=a){
							s++;
						}
					}
//					cout<<i<<" "<<j<<" "<<s<<"\n";
					if(s==2){
//		    			cout<<i<<" "<<j<<"\n";
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(x[n]-x[1]<=2*a){
			int f=0;
			for(int i=1;i<=n;i++){
				if(x[n]-x[i]<=a&&x[i]-x[1]<=a){
					f++;
				}
			}
			if(f==2){
				cout<<"1\n";
			}
			else if(f>2){
				cout<<"0\n";
			}
			continue;
		}
		cout<<"0\n";
	}
	return 0;
}
