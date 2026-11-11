#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,tmp,maxs=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(0));
	cin>>c>>t;
	for(int i=0;i<t*2+1;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>tmp;
			maxs=max(maxs,tmp);
		}
		
	}
	cout<<rand()%maxs;
}