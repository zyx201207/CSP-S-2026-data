#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

namespace solution{
	void main(){
		string A,B,C,D;
		cin>>A>>B>>C>>D;
		if(A==C) cout<<1;
		else cout<<0;
		string E = B;
		E.pop_back();
		string F = D;
		F.pop_back();
		if(A==C&&E==F) cout<<1;
		else cout<<0;
		if(A==C&&E==F&&B.back()<='C'&&D.back()<='C') cout<<1;
		else if(A==C&&E==F&&B.back()>'C'&&D.back()>'C') cout<<1;
		else cout<<0;
		if(A==C&&E==F&&B.back()<='C'&&D.back()<='C'&&abs(B.back()-D.back())==1) cout<<1;
		else if(A==C&&E==F&&B.back()>'C'&&D.back()>'C'&&abs(B.back()-D.back())==1) cout<<1;
		else cout<<0;
	}
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solution::main();
	return 0;
}

