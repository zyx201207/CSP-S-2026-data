#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,t=1;
string s;
struct node{
	LL x,l,r;
	char c;
}a[200000+10];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		a[i].l=t;
		t+=a[i].x;
		a[i].r=t-1;
	}
	LL l=1,r=n,sum=0;
	while(l<=r){
		LL k=min(a[l].r-a[l].l+1,a[r].r-a[r].l+1);
		if(a[l].c!=a[r].c) sum+=k;
		if(a[l].r-a[l].l+1>k){
			if(a[l].c!=a[r-1].c) sum+=a[l].r-a[l].l+1-k;
			a[r-1].l=a[l].r+1;
		}
		if(a[r].r-a[r].l+1>k){
			if(a[r].c!=a[l+1].c) sum+=a[r].r-a[r].l+1-k;
			a[l+1].l=a[r].r+1;
		}
		l++;
		r--;
	}
	cout<<sum;
    return 0;
}
