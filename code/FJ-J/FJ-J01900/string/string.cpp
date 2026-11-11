#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct num{
	int s;
	char d;
}a[200005];
long long l=1,r,l1=1,r1=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].d;
		r1+=a[i].s;
	}
	while(l1<r1){
		int ooo=min(a[l].s,a[r].s);
		if(a[l].d!=a[r].d) ans+=ooo;
		a[l].s-=ooo,a[r].s-=ooo;
		if(a[l].s==a[r].s) l++,r--;
		else if(a[l].s>a[r].s) r--;
		else if(a[l].s<a[r].s) l++;
		l1+=ooo,r1-=ooo;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
