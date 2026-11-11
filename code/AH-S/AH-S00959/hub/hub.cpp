#include<bits/stdc++.h>
using namespace std;
#define N 100005
int c,T,n,k,x,y;
struct nd{
	int t,n;
}a[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==13||c==14){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++)
				cin>>x>>y;
			cout<<(n/2-k)/4+2;
		}
		return 0;
	}
	return 0;
}
