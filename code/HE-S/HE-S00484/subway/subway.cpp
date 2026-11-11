#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[12525],k[21],mp[125255][125255],ans;//m<=125250
struct dt{
	int zs[21],t[21],js=0;
}s[125255];
int zdt(int x,int y){
	if(x==y)
	return ans;
	for(int i=1;i<=s[x].js;i++){
		for(int j=1;j<=k[s[x].zs[i]];j++){
			
			zdt(j,y);
		}
	}
}
int loveccf(int x,int y){
	int o=0;
	for(int i=1;i<=p;i++){                        
        for(int j=1;j<=p;j++){
 			if(s[x].zs[i]==s[y].zs[j]){
 				
 				return w[x]+w[y]+s[x].t[i]+s[y].t[i];
			 }
		}
	}

	return zdt(x,y);	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>mp[i][j]>>s[i].t[j];
			s[i].zs[s[i].js++]=i;
		}
	}
	int x,y;
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		
		
		ans=0;
		for(int i=1;i<=p;i++){                        
        for(int j=1;j<=p;j++){
 			if(s[x].zs[i]==s[y].zs[j]){
 				
 				cout<<w[x]+w[y]+s[x].t[i]+s[y].t[i]<<endl;
 				break;
			 }
		}
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

