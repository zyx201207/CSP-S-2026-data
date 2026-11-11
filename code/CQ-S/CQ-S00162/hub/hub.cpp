#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5,ZN=2*1e6+1;
int c,t;
vector<int> v[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<rand()%n+1<<"\n";
	}
	return 0;
}
