#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
vector<int> p[N];
int dp[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<(((n-1)/2-k)+1)/4+1<<endl;
	}
	return 0;
}

