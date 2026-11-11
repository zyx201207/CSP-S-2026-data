#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
int n;
struct node{
	int x;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].c;
	ll ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l].x==a[r].x){
			if(a[l].c!=a[r].c)ans+=a[l].x;
			l++,r--;
		}
		else if(a[l].x<a[r].x){
			if(a[l].c!=a[r].c)ans+=a[l].x;
			a[r].x-=a[l].x;
			l++;
		}
		else{
			if(a[l].c!=a[r].c)ans+=a[r].x;
			a[l].x-=a[r].x;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

