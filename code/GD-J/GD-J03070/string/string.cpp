#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int n;
ll ans;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i].x,&a[i].c);
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				a[r].x=0;
				r--;
			}else{
				a[r].x-=a[l].x;
				ans+=a[l].x;
				a[l].x=0;
				l++;
			}
		}else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				a[r].x=0;
				r--;
			}else{
				a[r].x-=a[l].x;
				a[l].x=0;
				l++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
