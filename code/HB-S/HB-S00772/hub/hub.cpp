#include<bits/stdc++.h>
using namespace std;
void com(int x,int y){
	find(x)=find(y);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int ls;
			if(j%2==1){
				cin>>a[(i+1)/2];
				fa[a[(i+1)/2]]=i;
			}
			else cin>>t[i/2];
		}
	}
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,fa[20050];
long long w[20050];
int find(int x){
	if(fa[x]!=x) fa[x]=find[fa[x]];
	return fa[x];
}
void com(int x,int y){
	find(x)=find(y);
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int ls;
			if(j%2==1){
				cin>>a[(i+1)/2];
				fa[a[(i+1)/2]]=i;
			}
			else cin>>t[i/2];
		}
	}
	while(q--){
		cin>>x>>y;
		if(fa[x]==fa[y]){
			
		}
	}
    return 0;
}*/
