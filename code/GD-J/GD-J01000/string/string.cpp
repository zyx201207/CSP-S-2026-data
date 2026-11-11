#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct str{
	ll len;
	char ch;
}a[N];
ll sum,ans;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].len,&a[i].ch);
		sum+=a[i].len;
	}
	ll l=1,r=n,siz=0;
	while(l<=r&&l&&r<=n){
		char x=a[l].ch,y=a[r].ch;
		if(x==y){
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				siz+=a[l].len;
				l++;
			}
			else if(a[r].len<a[l].len){
				a[l].len-=a[r].len;
				siz+=a[r].len;
				r--;
		   }
			else{
				siz+=a[l].len;
				l++;
				r--;
			}
		}
		else{
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				ans+=a[l].len;
				siz+=a[l].len;
				l++;
			}
			else if(a[r].len<a[l].len){
				a[l].len-=a[r].len;
				ans+=a[r].len;
				siz+=a[l].len;
				r--;
			}
			else{
				ans+=a[r].len;
				siz+=a[l].len;
				l++;
				r--;
			}
		}
		if(siz==sum/2){
			break;
		}
	}
	printf("%lld",ans);
	return 0;
} 
