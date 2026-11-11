#include<bits/stdc++.h>
#define int long long
//voidÄ©Î²Òª¼Óreturn;
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string p;
	int n;
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		p.append(string(a,c));
	}
	
	
	n=p.size();
	p="#"+p;
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		if(p[i]!=p[n-i+1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
// 68
