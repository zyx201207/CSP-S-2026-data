#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int> > a;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		if(n%2==0&&k%2==0){
			cout<<(n+k)/n<<endl;
			continue;
		}
		cout<<n/k<<endl;
	}
	return 0;
}
