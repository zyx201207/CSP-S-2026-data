#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=2e17;
int C,T;
int u[2000006],v[2000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&C,&T);
	while(T--){
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			scanf("%d %d",&u[i],&v[i]);
		}
		sort(u+1,u+n);
		bool flag=1;
		for(int i=1;i<n;i++){
			if(u[i]-u[i-1]!=1){
				flag=0;
				break;
			}
		}
		if(flag)cout<<"1\n";
		else cout<<"2\n";
	}
	return 0;
}
