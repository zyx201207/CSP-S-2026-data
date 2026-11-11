#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int g[200005];
char c[200005];
struct edge{
	int g;
	char c;
};
vector<edge>v1,v2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int d=0;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>c[i];
		d+=g[i];
	}
	if(d%2==1){
		int siz=0,h=d/2;
		h++;
		for(int i=1;i<=n;i++){
			siz+=g[i];
			if(siz>=h){
				g[i]--;
				break;
			}
		} 
		d--;
	}
	bool flag=0;
	int cntg=0;
	for(int i=1;i<=n;i++){
		if(flag==0){
			if(cntg+g[i]>(d/2)){
				v1.push_back({(d/2)-cntg,c[i]});
				v2.push_back({cntg+g[i]-(d/2),c[i]});
				flag=1;
			}
			else cntg+=g[i],v1.push_back({g[i],c[i]});
			if(cntg==(d/2)) flag=1;
		}
		else{
			v2.push_back({g[i],c[i]});
		}
	}
	int ans=0;
	int g1=0,g2=v2.size()-1;
	int pg=v1.size();
	while((g1<=pg-1)&&(g2>=0)){
		if(v1[g1].g==0){
			g1++;
			continue;
		}
		if(v2[g2].g==0){
			g2--;
			continue;
		}
		if(v1[g1].g>v2[g2].g){
			if(v1[g1].c!=v2[g2].c) ans+=v2[g2].g;
			else ans+=0;
			v1[g1].g-=v2[g2].g;
			g2--;
		}
		else{
			if(v1[g1].c!=v2[g2].c) ans+=v1[g1].g;
			else ans+=0;	
			v2[g2].g-=v1[g1].g;
			g1++;		
		}
	}
	cout<<ans;
	return 0;
}
