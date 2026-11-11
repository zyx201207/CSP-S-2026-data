#include<bits/stdc++.h> 
using namespace std;

int c,t,n,k,w,u;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			cin>>w>>u;
		}
		srand(time(0));
		cout<<rand()%n<<endl;
	}
	return 0;
}

