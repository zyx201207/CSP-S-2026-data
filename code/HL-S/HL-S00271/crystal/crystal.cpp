#include<bits/stdc++.h>
using namespace std;
long long m,n,target,pl,ans=0,mark=0;
bool flag=false;
long long krystal[500005];
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>krystal[i];
	}
	sort(krystal+1,krystal+1+n);
	pl=n;
	long long end=n;
	while(end>=1){
		long long energy=m;
		target=krystal[pl-mark];
		for(long long i=pl-mark-1;i>=0;i--){
			energy-=abs(target-krystal[i]);
			if(abs(target-krystal[i])==0) {
				mark++;
				//flag=true;
			}
			//cout<<i+1<<" ";
			if(energy<0){
				ans=max(ans,pl-end+1);
				//cout<<endl;
				//cout<<ans<<endl;
				//cout<<endl;
				//cout<<mark<<endl;
				break;
			}
			end=i;
		}
		mark=0;
		pl--;
	}
	cout<<ans<<endl;
	return 0;
}
