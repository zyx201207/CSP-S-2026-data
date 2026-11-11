#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int t;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].t);
		cin>>a[i].s;
	}
	int lft=1,rit=n;
	long long ans=0;
	for(int i=1;i<=n and lft<rit and rit>=1 and lft<=n;i++){
		if(a[lft].s!=a[rit].s){
			if(a[lft].t>a[rit].t){
				ans+=a[rit].t;
				rit--;
				a[lft].t-=a[rit+1].t;
			}
			else if(a[lft].t<a[rit].t){
				ans+=a[lft].t;
				lft++;
				a[rit].t-=a[lft-1].t;
			}
			else{
				ans+=a[rit].t;
				rit--;
				lft++;
			}
		}
		else{
			if(a[lft].t>a[rit].t){
				rit--;
				a[lft].t-=a[rit+1].t;
			}
			else if(a[lft].t<a[rit].t){
				lft++;
				a[rit].t-=a[lft-1].t;
			}
			else if(a[lft].t=a[rit].t){
				lft++;rit--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
