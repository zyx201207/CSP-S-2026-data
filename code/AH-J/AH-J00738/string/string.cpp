#include<iostream>
#include<cstdio>
#include<string>

using namespace std;
using LL = long long;
const LL N = 2e5 + 5;

LL n,ans;
string s;
struct Node{
	LL len;
	char ch;
}a[N];
void solve(){
	LL i=1,j=n;
	while(i<j){
		if(a[i].ch!=a[j].ch){
			if(a[i].len>a[j].len){
				ans+=a[j].len;
				a[i].len-=a[j].len;
				j--;
			}else if(a[i].len<a[j].len){
				ans+=a[i].len;
				a[j].len-=a[i].len;
				i++;
			}else{
				ans+=a[i].len;
				i++,j--;
			}
		}else{
			if(a[i].len>a[j].len){
				a[i].len-=a[j].len;
				j--;
			}else if(a[i].len<a[j].len){
				a[j].len-=a[i].len;
				i++;
			}else{
				i++,j--;
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		cin>>a[i].len>>a[i].ch;
	}
	solve();
	printf("%lld",ans);

	return 0;
}
