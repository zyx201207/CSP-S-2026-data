#include<bits/stdc++.h>
using namespace std;

int a[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,id=n;
		long long x,d;
		cin>>n>>d>>x;
		for(int i=1;i<n;i++){
			long long y;cin>>y;
			a[i]=y-x;x=y;
			if(a[i]>d)id=i;
		}
		long long cnt=0;
		int ans=0,id1=0;
		for(int i=1;i<id;i++){
			a[i]=0;
			for(int j=i;j<id&&cnt<=d+a[i];j++){
				cnt+=a[j];
				if(cnt==d+a[i]+a[j]&&j-i>=2){
					ans++;
					break;
				}
				
			}
			cnt=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
