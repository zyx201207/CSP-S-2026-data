#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,x[N],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		ans=0;
		for(int i=1;i<=n;i++){
			int l,r,j=i+1;
			if(x[i]+d>x[n])
				break;
			j=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			l=j-1;
			if(x[l]+d>x[n])
				break;
			r=upper_bound(x+1,x+n+1,x[l]+d)-x-1;
			if(x[r]-x[l-1]<=d)
				continue;
			if(r<=j)
				continue;
			int b=i,e=r;
			while(b>1){
				b--;
				if(x[b+2]-x[b]<=d||x[b+1]-x[b]>d){
					b++;
					break;
				}
			}
			while(e<n){
				e++;
				if(x[e]-x[e-2]<=d||x[e]-x[e-1]>d){
					e--;
					break;
				}
			}
			ans+=(i-b+1)*(e-r+1); 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
