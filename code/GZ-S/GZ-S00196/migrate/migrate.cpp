#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ma[3008]={},n,d,ans=0;;
		cin>>n>>d;
		long long l=0,sum=0,a[3008]={};
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			sum=a[l]-a[i];
			sum=abs(sum);
			if(sum>d){
				ma[l]=i-1;
				l++;
			}
			if(i==n){
				while(l<=n){
					ma[l]=n;
					l++;
				}
			}
		} 
		
		long long sml=6000,ou=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				queue<pair<long long,long long> >dl;
				sml=6000,ou=1;
				dl.push({i,0});
				while(dl.size()){
					long long num=dl.front().second,v=dl.front().first;
					dl.pop();
					if(v==j){
						if(sml>num){
							sml=num;
							ou=1;
							
						}else if(num==sml){
							ou++;
						}
					}
					if(num>=sml)continue;
					for(long long k=v+1;k<=j;k++){
						if(abs(a[v]-a[k])>d)break;
						dl.push({k,num+1});
					}
				}
				if(ou==2){
					ans++;
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}
