//GZ-J00415 兴义市弘毅中学 程峻熙 
#include<bits/stdc++.h>
using namespace std;
long long a,ans,l=1,r,b,c,d,mid;
struct str{
	long long num;
	char ch;
}p[500010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&a);
	getchar();
	for(int i=1;i<=a;i++){
		scanf("%lld %c",&p[i].num,&p[i].ch);
		getchar();
		b+=p[i].num;
	}
	ans=b/2,r=a;
	while(l<=r){
		if(l==r){
			ans-=p[l].num/2;
			break;
		}
		if(p[l].num>p[r].num){
			p[l].num-=p[r].num;
			if(p[l].ch==p[r].ch) ans-=p[r].num;
			r--;
		}
		else if(p[l].num<p[r].num){
			p[r].num-=p[l].num;
			if(p[r].ch==p[l].ch) ans-=p[l].num;
			l++;
		}
		else{
			if(p[r].ch==p[l].ch) ans-=p[l].num;
			l++,r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
