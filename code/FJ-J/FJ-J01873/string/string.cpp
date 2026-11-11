#include <bits/stdc++.h>
using namespace std;
struct nd{
	long long x;
	char c;
}a[500005];
long long n,ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;char c;
		cin>>x>>c;
		a[i]={x,c};
	}
	int i=1,j=n;
	while(i<j){
		int mn=min(a[i].x,a[j].x);
		a[i].x-=mn;a[j].x-=mn;
		if(a[i].c!=a[j].c){
			ans+=mn;
		}
		if(a[j].x==0)j--;
		if(a[i].x==0)i++;
	}
	cout<<ans;
	return 0;
}
