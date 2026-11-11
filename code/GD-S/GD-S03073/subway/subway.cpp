#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,k,sm[10],x,y,mins=0;
struct node0{
	int a;
	int t;
};
//node0 szk[10];
struct node1{
	node0 szk[10];//k
};
node1 sn[10];//n
struct node3{
	int si,sk;
};
struct node2{
	int js=0;
	node3 sz[10];
};
node2 dw[10];//dw
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sm[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sn[i].szk.a>>sn[i].szk.t;
//			sn[i]=sk[j];
			dw[sn[i].szk.a].js++;//有几个 
			dw[sn[i].szk.a].sz[dw[sn[i].sk.a].js].si=i;//每一个所在i和k 
			dw[sn[i].szk.a].sz[dw[sn[i].sk.a].js].sk=k;//每一个所在i和k 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
				for(int j=1;j<=dw[x].js;j++){
					for(int z=1;z<=dw[y].js;z++){
						if(dw[j].sz[j].si==dw[z].sz[z].si){
							mins=min(mins,sm[x]+sm[y]+sn[dw[j].sz[j].si].sk.t+sn[dw[z].sz[z].si].sk.t);
						}
					}
				}
				cout<<mins<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
