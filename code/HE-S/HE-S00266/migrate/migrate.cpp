#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long c,t;
long long a[N],f1[N],f2[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		long long ans=0;
		for(int i=1;i<=n;i++){
			memset(f1,0,sizeof(f1));
			memset(f2,0,sizeof(f2));
			f2[i]=1;
			for(int j=i+1,k=1;j<=n;j++){
				while(a[j]-a[k]>d && k<j){
					k++;
				}
				if(k==j) break;
				f1[j]=f1[k]+1;
				f2[j]+=f2[k];
				for(int l=k+1;l<j && f1[k]==f1[l];l++){
					f2[j]+=f2[l];
					if(f2[j]>2){
						ans=ans;
					}else{
						ans++;
					}
				}
			}
		} 
		cout<<ans<<endl;
	}
	return 0;
} 
