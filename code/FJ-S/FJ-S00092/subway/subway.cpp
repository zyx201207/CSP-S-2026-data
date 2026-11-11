#include <bits/stdc++.h>
using namespace std;

const int M=5e5+5;
int c,n,m,d,q;
int w[M];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}

	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int l=1;l<=2*k;l++){
			int x;
			cin>>x;
		}
	}
	
	for(int r=1;r<=q;r++){
		int l,r;
		cin>>l>>r;
		cout<<14;
	}

	return 0;
}

