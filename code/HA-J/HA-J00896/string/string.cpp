#include<bits/stdc++.h>
using namespace std;
struct Node{
	char c;
	int a;
};
Node a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i].a,&a[i].c);
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].a==a[r].a && a[l].c==a[r].c){
			l++;
			r--;
		}else if(a[l].a==a[r].a && a[l].c!=a[r].c){
			ans+=a[l].a;
			l++;
			r--;
		}else if(a[l].a!=a[r].a && a[l].c!=a[r].c){
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				ans+=a[r].a;
				r--;
			}else{
				a[r].a-=a[l].a;
				ans+=a[l].a;
				l++;
			}
		}else if(a[l].a!=a[r].a && a[l].c==a[r].c){
			if(a[l].a>a[r].a){
				a[l].a-=a[r].a;
				r--;
			}else{
				a[r].a-=a[l].a;
				l++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
