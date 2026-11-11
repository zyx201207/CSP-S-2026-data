#include<bits/stdc++.h>
using namespace std;

int a[100005];
int b[100005];
int start;
int js;
int ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>m>>d>>q;
	while(q--){
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		cin>>start;
		cin>>js;
		for(int i=start;i<=js;i++){
			ans+=a[i]+b[i];
		}
		cout<<ans;
	}
	
	
	
	
	return 0;
}
