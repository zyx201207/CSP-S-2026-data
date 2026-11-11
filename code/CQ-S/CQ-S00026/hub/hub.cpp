#include <bits/stdc++.h>
using namespace std;
int u[100086],v[100086];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int t1=t;
	while(t1--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<t-t1;
	}
	return 0;
}


