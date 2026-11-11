#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,s[N],cnt=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n);
	int cnt=n-2;
	int k=s[n-1];
	m-=1;
	while(m--){
		k &= s[cnt];
		cnt--;
	}
	cout<<k;
	return 0;
} 
