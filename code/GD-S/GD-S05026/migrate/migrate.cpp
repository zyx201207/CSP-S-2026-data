#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,st[N];
long long d;
long long x[N],cr[N],qs[N];
int main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			qs[i]=x[i]+qs[i-1]-x[i-1];
		}
		for(int k=1;k<=n;k++){
			memset(cr,(long long)0,sizeof(cr));
			memset(st,(long long)0,sizeof(st));
			for(int i=k;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<"dis form "<<i<<" to "<<j<<" is: "<<qs[j]-qs[i]<<endl;
					if(qs[j]-qs[i]<=d){
						if(!st[j]){
							//cout<<"first time reach "<<j<<endl;
							st[j]=st[i]+1;
							cr[j]++;
						}else{
							//cout<<"reach "<<j<<" again"<<endl;
							if(st[i]+1==st[j])
								cr[j]++;
						}
					}else break;
				}
			}
			for(int i=3;i<=n;i++){
				if(cr[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

