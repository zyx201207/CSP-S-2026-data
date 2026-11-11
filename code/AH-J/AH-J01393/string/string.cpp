#include<bits/stdc++.h>
using namespace std;
struct node{
	char c;
	long long number;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].number>>a[i].c;
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		long long t=min(a[l].number,a[r].number);
		a[l].number-=t;
		a[r].number-=t;
		if(a[l].c!=a[r].c)ans+=t;
		if(a[l].number==0)l++;
		else r--;
	}
	cout<<ans<<'\n';
	return 0;
}
