#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int c,n,m,d,q,s[maxn][21],s1[maxn];
vector<int> v[maxn];
void f(int b,int e){
	int cnt=0;
	for(int i=1;i<=d;i++){
		for(int j=1;j<=m;j++){
			if(s[j][i])v[j].push_back(i);
		}
	}
	int flag=0,same=0;
	for(int i=0;i<v[b].size();i++){
		for(int j=0;j<v[e].size();j++){
			if(v[b][i]==v[e][j]){
				flag=1;
				same=v[b][i];
				break;
			}
		}
	}
	if(flag){
		cnt=s1[b]+s[b][same]+s[e][same]+s1[e];
		cout<<cnt<<endl;
	}else{
		cnt=INT_MAX;
		int nas=0,nas1=0,nas2=0;
		for(int i=0;i<v[b].size();i++){
			for(int j=0;j<v[e].size();j++){
				for(int k=1;k<=m;k++){
					if(k==b||k==e||v[k].size()==1){
						continue;
					}
					int f1=0,f2=0;
					for(int l=0;l<v[k].size();l++){
						if(v[k][l]==v[b][i]){
							f1=1;
							nas1=l;
							if(f2)break;
						}
						if(v[k][l]==v[e][j]){
							f2=1;
							nas2=l;
							if(f1)break;
						}
					}
					if(f1&&f2){
						nas=k;
						cnt=min(cnt,s1[b]+s[b][nas1+1]+s[nas][nas1+1]+s[nas][nas2+1]+s[e][nas2+1]+s1[e]);
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		while(p--){
			int r,t;
			cin>>r>>t;
			s[r][i]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int b,e;
		cin>>b>>e;
		f(b,e);
	}
	fclose(stdin);
	fclose(stdout);
  return 0;
} 
