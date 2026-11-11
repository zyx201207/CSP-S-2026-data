#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll a[200001];
ll c[200001];
ll ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>k)&1){
				cnt++;
			}else{
				break;
			}
		}if(cnt<m){
			for(int i=1;i<=cnt;i++){
				a[i]-=(1ll<<k);
			}int p1=1,p2=cnt+1,top=0;
			while(p1<=cnt&&p2<=n){
				if(a[p1]<a[p2]){
					c[++top]=a[p2++];
				}else{
					c[++top]=a[p1++];
				}
			}while(p1<=cnt){
				c[++top]=a[p1++];
			}while(p2<=cnt){
				c[++top]=a[p2++];
			}for(int i=1;i<=top;i++){
				a[i]=c[i];
			}
		}else{
			ans+=(1ll<<k);
			n=cnt;
		}
	}printf("%lld\n",ans);
}