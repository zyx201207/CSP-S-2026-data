#include<bits/stdc++.h>
using namespace std;
int const MAXN=(int)2e5+5;
struct Node{
	long long g;
	char c;
};
Node a[MAXN];
int n;
int top=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	//~ printf("n=%d\n",n);
	for(int i=1;i<=n;i++){
		int x;
		char y;
		scanf("%d %c",&x,&y);
		//~ printf("x=%d y=%c",x,y);
		if(i==1 || a[top].c!=y){
			a[++top].g=x;
			a[top].c=y;
		}
		else{
			a[top].g+=x;
		}
	}
	int l=1,r=top;
	for(int i=1;i<=top;i++){
		if(l==r || l>r){
			break;
		}
		if(a[l].c==a[r].c && a[l].g==a[r].g){
			l++;
			r--;
		}
		else if(a[l].c==a[r].c){
			if(a[l].g>a[r].g){
				a[l].g-=a[r].g;
				r--;
				
			}
			else{
				a[r].g-=a[l].g;
				l++;
			}
		}
		else{
			if(a[l].g>a[r].g){
				a[l].g-=a[r].g;
				ans+=a[r].g;
				r--;
			}
			else{
				a[r].g-=a[l].g;
				ans+=a[l].g;
				l++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
