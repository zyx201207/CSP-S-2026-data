#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct aaa{
	int s;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].s>>a[i].c;
	for(int i=1,j=n;i<j;){
		//cout<<i<<' '<<j<<'\n';
		if(a[i].s==0)i++;
		if(a[j].s==0)j--;
		if(a[j].c!=a[i].c)ans+=min(a[i].s,a[j].s);
		int t=min(a[i].s,a[j].s);
		a[i].s-=t,a[j].s-=t; 
	}
	cout<<ans;
}
