#include<bits/stdc++.h>
using namespace std;
int n;
long long len=0,ans;
struct node{
	char c;
	long long l,left,right;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	char h;
	for(int i=1,l;i<=n;i++){
		scanf("%d",&l);
		cin>>h;
		if(h==a[i-1].c){
			a[i-1].l+=l;
			a[i-1].right+=l;
			i--,n--;
		}else{
			a[i].l=l;
			a[i].c=h;
			a[i].left=len+1;
			a[i].right=len+l;
		}
		len+=l;
	}
	long long mid=(len>>1),l=1,r=len,lx=1,rx=n;
	while(lx<rx){
		if(a[lx].right-l<r-a[rx].left){
			if(a[lx].c!=a[rx].c)ans+=a[lx].right-l+1;
			r-=a[lx].right+1-l;
			l=a[lx].right+1;
			lx++;
		}else if(a[lx].right-l>r-a[rx].left){
			if(a[lx].c!=a[rx].c)ans+=r-a[rx].left+1;
			l+=r-a[rx].left+1;
			r=a[rx].left-1;
			rx--;
		}else{
			if(a[lx].c!=a[rx].c)ans+=r-a[rx].left+1;
			l=a[lx].right+1;
			r=a[rx].left-1;
			lx++,rx--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
