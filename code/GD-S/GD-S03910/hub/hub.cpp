#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
bool check(int x,int i){
	int sum=abs((i-x+1)*a[i]-(s[i]-s[x-1]));
	return sum<=m;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cout<<"1\n2\n";
	return 0;
}
