#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct qwq{
	int cnt;
	char c;
}a[N];
int n;
int ans;
signed main(){
	freopen("string.in" ,"r",stdin );
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("\n%lld %c",&a[i].cnt,&a[i].c);
	for(int i=1,j=n;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].cnt>a[j].cnt){
				a[i].cnt-=a[j].cnt; 
				j--;
			}
			else{
				a[j].cnt-=a[i].cnt;
				i++;
			}
		}
		else{
			if(a[i].cnt>a[j].cnt){
				a[i].cnt-=a[j].cnt; 
				ans+=a[j].cnt;
				j--;
			}
			else{
				a[j].cnt-=a[i].cnt;
				ans+=a[i].cnt;
				i++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
