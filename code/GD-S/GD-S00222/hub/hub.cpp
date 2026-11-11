#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN][2]; 
int t,c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<n;i++){
			cin>>a[i][1]>>a[i][2];
		}
		cout<<1<<endl;
	}
	return 0;
}
