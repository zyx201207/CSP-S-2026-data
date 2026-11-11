#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct Road{
	int u,v;
}ro[1000010];
int cnt=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int uu,vv;
		for(int i=1; i<n; i++){
			cin>>uu>>vv;
			ro[++cnt].u=uu;
			ro[++cnt].v=vv;
		}
		//Sorry,but I can't understand this question.
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
