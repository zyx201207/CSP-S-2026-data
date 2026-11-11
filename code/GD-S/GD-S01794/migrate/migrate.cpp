#include<bits/stdc++.h>
using namespace std;
long long we[100005],a[100005],x[100005];
long long ans=0;
long long c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(d<=1){
			cout<<"0"<<endl;
			continue;
		}
		long long minn=99999999;
		long long maxx=0;
		for(int i=1;i<=n;i++){
			cin>>we[i];
			minn=min(minn,we[i]);
			maxx=max(maxx,we[i]);
		} 
		if(minn<=0){
			minn=abs(minn);
			for(int i=1;i<=n;i++){
				we[i]+=minn;
				x[we[i]]++;
				
			}
			maxx+=minn;
		}else {
			for(int i=1;i<=n;i++){
				x[we[i]]++;
			}
		}
		for(int i=d;i<=maxx;i++){
			a[i]=a[i-1]+x[i];
		}
		ans=0;
		
		for(int i=1;i<=maxx-1;i++){
			if(we[i]+d>=we[i+2]&&we[i+1]+d>=we[i+3]){
				if(we[i]+d>we[i+1]&&we[i+2]+d>we[i+3]){
					if(we[i]+d<we[i+3]){
						ans++;
						cout<<endl<<we[i]<<" "<<we[i+1]<<" "<<we[i+2]<<" "<<we[i+3]<<" "<<we[i+4]<<endl;
					}
						
						
					
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} //Oct31==Dec25?
