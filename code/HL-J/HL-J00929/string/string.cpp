#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int num;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1;int r=n;
	while(l<r){
		if(a[l].num>a[r].num){
			if(a[l].c!=a[r].c)ans+=a[r].num;
			a[l].num-=a[r].num;
			r--;
		}
		else{
			if(a[l].c!=a[r].c)ans+=a[l].num;
			a[r].num-=a[l].num;
			l++;
		}
	}
	cout<<ans;
	return 0;
}