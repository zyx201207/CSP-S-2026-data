#include "bits/stdc++.h"
using namespace std;
#define LL long long
const int N=2e5+5;
struct node{
	int a;
	char c;
}myy[N]; 
int n;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++) scanf ("%d %c",&myy[i].a,&myy[i].c);
	int l=1,r=n;
	LL ans=0;
	while (l<r){
		if (myy[l].c==myy[r].c){
			if (myy[l].a<myy[r].a)
				myy[r].a-=myy[l++].a;
			else 
				if (myy[l].a>myy[r].a)
					myy[l].a-=myy[r--].a;
				else l++,r--;
		}
		else {
			if (myy[l].a<myy[r].a){
				myy[r].a-=myy[l].a;
				ans+=myy[l++].a;
			}	
			else 
				if (myy[l].a>myy[r].a){
					myy[l].a-=myy[r].a;
					ans+=myy[r--].a;
				}
				else {
					r--;
					ans+=myy[l++].a;
				}
		}
	}
	printf ("%lld\n",ans);
	return 0;
}

