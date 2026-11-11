#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(c==11||c==12){
			int g;
			for(int i=2;i<=n;i++){
				if((a[i]-a[1])>d) {
					g=i-1; break;
				}
			}
			int r=(g-1)*(a[2]-a[1]);
			if(a[g]+r>a[n]||a[1]+d<a[2]||g+g-2>n||a[1]+d>a[n]||g==2) cout<<0;
			else cout<<n-(g+g-2)+1;
			cout<<endl; continue;
		}
		if(c==13||c==14){
			
		}
	}
	return 0;
}
