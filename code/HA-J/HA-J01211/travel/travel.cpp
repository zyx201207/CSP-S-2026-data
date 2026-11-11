#include<bits/stdc++.h>
using namespace std;
char q,w,e,r,t,y,u,i,o,p;
bool a=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>q>>w>>e>>r>>t>>y>>u>>i>>o>>p;
	if(q==y&&w==u&&a)cout<<1;else{a=0;cout<<0;}
	if(e==i&&r==o&&a)cout<<1;else{a=0;cout<<0;}
	if((t>64&&t<68&&p>64&&p<68||t>67&&t<71&&p>67&&p<71)&&a)cout<<1;else{a=0;cout<<0;}
	if((t==65&&p==66||t==66&&p==67||t==68&&p==70||
	t==66&&p==65||t==67&&p==66||t==70&&p==68)&&a)cout<<1;else{a=0;cout<<0;}
	return 0;
}
