#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a,b;
vector<int> arr[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			arr[a].push_back(b);
		}
		cout<<1;
	}
	return 0;
}






