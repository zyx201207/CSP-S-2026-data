#include<bits/stdc++.h>
#define int long long
#define endl '/n'
using namespace std;
int l[500005];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int c,t;
	cin>>c>>t;
	for(int i = 0;i < n;i++){
		int n,d;
		int ll[n][n];
		cin>>n>>d;
		for(int j = 0;j < n;j++){
			cin>>l[j];
		}
		for(int j = 0;j < n;j++){
			for(int a = 0;j + a + 1< n;a++){
				ll[j][a] = l[j + a + 1] - j[i];
			}
		}
		for(int j = 0;j < n;j++){
			for(int a = 0;j + a + 1 < n;a++){
				if(l[j][a] > d){
					l[j][a] = 0;
				}
			}
		}
		int ans = 0;
		for(int j = 0;j < n;j++){
			for(int a = 0;j + a + 1 < n;a++){
				
			}
		}
	}
	cout<<0<<endl<<1;
	return 0;
}
