#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	char c;
	ll  num;
}a[200010];
ll m,n,x,ans;	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++){
		char ch;
		scanf("%lld %c",&x,&ch);
		if(ch==a[n].c)a[n].num+=x;
		else{
			a[++n].num=x;
			a[n].c=ch;
		}
	}
	ll l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c)ans+=min(a[l].num,a[r].num);
		if(a[l].num>a[r].num){
			a[l].num-=a[r].num;
			a[r].num=0;
			r--;
		}
		else if(a[l].num==a[r].num){
			a[l].num=0;
			a[r].num=0;
			l++;
			r--;
		}
		else{
			a[r].num-=a[l].num;
			a[l].num=0;
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
