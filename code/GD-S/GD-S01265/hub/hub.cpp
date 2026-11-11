#include<bits/stdc++.h>
const int N=1e6+10;
using namespace std;
int c,t,n,k,a[N];
vector<int>q;
bool cheak(int mid){
	if(k*mid>=(n-1))return true;
	else false;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
		}int l=0,r=n;
		while(l+1<r){
			int mid=(l+r)/2;
			if(cheak(mid))r=mid;
			else l=mid;
		}cout<<r<<'\n';
	}
	return 0;
}
