#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[200005],s;
bool ch(int x){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if((x&a[i])==x) cnt++;
	return cnt>=k;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=29;i>=0;i--)
		if(ch(s|(1<<i))) s|=(1<<i);
	cout<<s;
	return 0;
}
