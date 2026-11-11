#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c,t;
	cin>>c>>t;
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			int a[N];
			for(int i=1;i<=n;i++) cin>>a[i];
			if(a[2]-a[1]>d) cout<<"0"<<endl;
			else
			{
				cout<<n-3<<endl;
			}
		}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
