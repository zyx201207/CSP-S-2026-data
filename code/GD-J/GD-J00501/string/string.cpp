#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
struct Node{
	long long ll;
	int w;
}a[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	long long x;
	char z;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x,&z);
		a[i].w=z-'a';
		a[i].ll=x;
	}
	
	int l=1,r=n;
	while(l<r){
		if(a[l].w==a[r].w){
			if(a[l].ll<a[r].ll){
				a[r].ll-=a[l].ll;
				l++;
			}
			else if(a[l].ll>a[r].ll){
				a[l].ll-=a[r].ll;
				r--;
			}
			else l++,r--;
		}
		else{
			if(a[l].ll<a[r].ll){
				ans+=a[l].ll;
				a[r].ll-=a[l].ll;
				l++;
			}
			else if(a[l].ll>a[r].ll){
				ans+=a[r].ll;
				a[l].ll-=a[r].ll;
				r--;
			}
			else {
				ans+=a[l].ll;
				l++,r--;
				
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
