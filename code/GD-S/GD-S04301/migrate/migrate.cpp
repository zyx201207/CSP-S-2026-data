#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,top,ans,top1;
long long a[10005],ma;
int xb[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			xb[i]=0;
		}
		sort(a+1,a+1+n);
		xb[1]=1;
		for(int i=2;i<=n;i++){
			if(a[1]+d>=a[i]) xb[i]=1;
			else{
				ma=a[i-1];
				top=i;
				break;
			}
		}
		
		for(int i=top;i<=n;i++){
			if(a[i]>ma+d){
				ma=a[i-1];
				top1=top;
				top=i;
				break;
			}
			for(int j=1;j<=top;j++){
				if(a[j]+d>=a[i]) xb[i]++;
			}
			if(i==n) top=i+1;
		}
		
		while(top<=n)
		if(ma+d>=a[top])
		for(int i=top;i<=n;i++){
			if(i==n) top=i+1;
			if(a[i]>a[top1]+d){
				ma=a[i-1];
				top1=top;
				top=i;
				break;
			}
			for(int j=top1;j<=top;j++){
				if(a[j]+d>=a[i]) xb[i]++;
			}
		}
		else{
			ma=a[top];
			top++;
		} 
		
		for(int i=1;i<=n;i++) if(xb[i]==2) ans++;
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
	
}
