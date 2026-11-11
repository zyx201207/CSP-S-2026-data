#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+12;
struct node{
	int line,time;
};
int c,n,m,d,q;
int f[N][3];
int flag[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>f[i][0];
	}
	if(n==2){
	int k;
	cin>>k;
    for(int i=1;i<=k;i++){
    	int a,b;
    	cin>>a>>b;
    	flag[a]++;
    	f[a][2]=b;
	}
	cin>>k;
    for(int i=1;i<=k;i++){
    	int a,b;
    	cin>>a>>b;
    	flag[a]+=2;
    	f[a][3]=b;
	}
	int minn=1e18;
	for(int i=1;i<=m;i++){
		if(flag[i]/3){
			minn=min(minn,f[i][2]+f[i][3]);
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
			if(flag[a]==3&&flag[b]==3){
				cout<<min(min(f[a][1]+f[b][1],f[a][2]+f[b][2]),min(f[a][1]+f[b][2]+minn,f[a][2]+f[b][1]+minn))+f[a][0]+f[b][0]<<'\n';
			}
			else if(flag[a]==1&&flag[b]==3){
				 cout<<min(f[a][1]+f[b][1],f[a][1]+f[b][2]+minn)+f[a][0]+f[b][0]<<'\n';
			}
			else if(flag[a]==3&&flag[b]==1){
				cout<<min(f[a][1]+f[b][1],f[a][2]+f[b][1]+minn)+f[a][0]+f[b][0]<<'\n';
	}
			else if(flag[a]==2&&flag[b]==3){
				 cout<<min(f[a][2]+f[b][2],f[a][2]+f[b][1]+minn)+f[a][0]+f[b][0]<<'\n';
			}
			else if(flag[a]==3&&flag[b]==2){
				cout<<min(f[a][2]+f[b][2],f[a][1]+f[b][2]+minn)+f[a][0]+f[b][0]<<'\n';
	}
	       	else if(flag[a]==1&&flag[b]==1){
				 cout<<f[a][1]+f[b][1]+f[a][0]+f[b][0]<<'\n';
			}
			else if(flag[a]==2&&flag[b]==2){
				cout<<f[a][2]+f[b][2]+f[a][0]+f[b][0]<<'\n';
			}
		   	else if(flag[a]==1&&flag[b]==2){
				 cout<<f[a][1]+f[b][2]+minn+f[a][0]+f[b][0]<<'\n';
			}
			else if(flag[a]==2&&flag[b]==1){
				cout<<f[a][2]+f[b][1]+minn+f[a][0]+f[b][0]<<'\n';
	} 
}
	}
	else {
		cout<<"QAQ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
