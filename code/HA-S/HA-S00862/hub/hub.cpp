#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,cnt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int u,v;
		for(int i=1;i<n;i++)scanf("%d%d",&u,&v);
		cout<<++cnt<<"\n";
	}
	return 0;
}
