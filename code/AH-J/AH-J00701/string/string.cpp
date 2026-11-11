#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node{
	LL num;
	char ch;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n,sum=0,l=0,r=0,x=1,y;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld %c",&a[i].num,&a[i].ch);
	y=n;
	while(x<y){
		while(a[y].num<=l&&x<y){
			l-=a[y].num;
			y--;
		}
		while(a[x].num<=r&&x<y){
			r-=a[x].num;
			x++;
		}
		if(x+1==y){
			if(a[x].ch!=a[y].ch) sum+=min(a[x].num-r,a[y].num-l);
			break;
		}
		if(a[x].ch!=a[y].ch){
			sum+=max(a[x].num-r,a[y].num-l);
			if(a[x].num-r>a[y].num-l) l+=a[x].num-r-(a[y].num-l);
			if(a[x].num-r<a[y].num-l) r+=a[y].num-l-(a[x].num-r);
		}
		else if(a[x].num-r!=a[y].num-l){
			sum+=abs((a[x].num-r)-(a[y].num-l));
			if(a[x].num-r>a[y].num-l) l+=a[x].num-r-(a[y].num-l);
			if(a[x].num-r<a[y].num-l) r+=a[y].num-l-(a[x].num-r);
		}
		x++,y--;
	}
	cout<<sum;
	return 0;
}
