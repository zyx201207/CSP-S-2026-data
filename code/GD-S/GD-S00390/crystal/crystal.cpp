#include<bits/stdc++.h>
using namespace std;
void read(long long &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c)) f=(c=='-'?-1:1),c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=x*f;
}
const int N=5e5+10;
long long n,m,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+1+n);
	for(long long l=1,r=1,t=0;r<=n;r++){
		t+=(r-l)*(a[r]-a[r-1]);
		while(t>m) l++,t-=(a[r]-a[l-1]);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
