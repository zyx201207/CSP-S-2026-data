#include<bits/stdc++.h>
using namespace std;
struct node{
	int tp,vl;
};
const int N=500050;
int c,n,m,d,q;
int w[N],a[N],b[N],ta[N],tb[N],aa[1000],bb[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	if(n==2){
		int k1,k2;
		cin>>k1;
		for(int i=1;i<=k1;i++){
			cin>>a[i]>>ta[a[i]];
			aa[a[i]]++;
		}
		cin>>k2;
		for(int i=1;i<=k2;i++){
			cin>>b[i]>>tb[b[i]];
			bb[b[i]]++;
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			int c1,c2;
			if(aa[x]&&bb[x]) c1=3;
			else if(aa[x]) c1=1;
			else c1=2;
			if(aa[y]&&bb[y]) c2=3;
			else if(aa[y]) c2=1;
			else c2=2;
			int bd=w[x]+w[y];
			if(c1==c2||c1==3||c2==3){
				if(c1==1)
					cout<<bd+ta[x]+ta[y]<<'\n';
				else
					cout<<bd+tb[x]+tb[y]<<'\n';
			}
			else{
				int minn=2e9+1000;
				for(int i=1;i<=m;i++){
					if(aa[i]&&bb[i])
						minn=min(minn,ta[i]+tb[i]);
				}
				if(c1==1){
					cout<<bd+ta[x]+tb[y]+minn<<'\n';
				}
				else{
					cout<<bd+tb[x]+ta[y]+minn<<'\n';
				}
			}
		}
	}
	return 0;
}
//freopen("subway.in","r",stdin);
