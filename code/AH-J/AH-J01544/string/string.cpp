#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct st{
	int x;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].x,&a[i].c);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x!=a[r].x){
				if(a[l].x>a[r].x){
					a[l].x-=a[r].x;
					r--;
				}else{
					a[r].x-=a[l].x;
					l++;
				}
			}else{
				l++;
				r--;
			}
		}else{
			ans+=min(a[l].x,a[r].x);
			if(a[l].x!=a[r].x){
				if(a[l].x>a[r].x){
					a[l].x-=a[r].x;
					r--;
				}else{
					a[r].x-=a[l].x;
					l++;
				}
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
