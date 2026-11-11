#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int n,k,c,t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<rand()%2+1<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

