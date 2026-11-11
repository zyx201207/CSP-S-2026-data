#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,inf=4e18;
int n,m;
struct node{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	int L=1,R=n,cur=0;
	while(L<R){
		if(a[L].x>a[R].x){
			if(a[L].c!=a[R].c)cur+=a[R].x;
			a[L].x-=a[R].x;
			R--;
		}
		else if(a[L].x<a[R].x){
			if(a[L].c!=a[R].c)cur+=a[L].x;
			a[R].x-=a[L].x;
			L++;
		}
		else{
			if(a[L].c!=a[R].c)cur+=a[L].x;
			L++;
			R--;
		}
	}
	cout<<cur;
	return 0;
}

