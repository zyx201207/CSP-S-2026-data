#include<iostream>
using namespace std;
int n,l,r;
long long ans,len;
struct ckl{
	int m;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	r=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].m);
		cin>>a[i].c;
		len+=a[i].m;
	}
	while(1){
		if(a[l].c==a[r].c){
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				r--;
			}else{
				a[r].m-=a[l].m;
				l++;
			}
		}else{
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				ans+=a[r].m;
				r--;
			}else{
				a[r].m-=a[l].m;
				ans+=a[l].m;
				l++;
			}
		}
		if(l==r){
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
