#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
	int s1[m+1];
	int vs1[m+1][2];
	for(int i=1;i<=m;i++){
		cin>>s1[i];
	}
	for(int ii=1;ii<=n;ii++){
		int nn;
		cin>>nn;
		for(int j=1;j<=nn;j++){
			cin>>vs1[j][0]>>vs1[j][1];
		}
		}
		for(int i=1;i<=q;i++){
			int mdd,qsd;
			ans=0;
			cin>>qsd>>mdd;
			ans+=s1[qsd];
			ans+=s1[mdd];
			for(int j=qsd;j<=mdd;j++){
				for(int v=1;v<=n;v++){
					if(vs1[v][0]>=qsd&&vs1[v][0]<mdd)
						ans+=vs1[v][1];
				}
			}
			cout<<ans<<endl;
		}
return 0;}
//0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2

