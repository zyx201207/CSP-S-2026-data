#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int s;
int path[500005];
int w=1;
int p;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>path[i];
	}
	s=abs(path[2]-path[1]);
int a=m;
	for(int i=0;i<=m;i+=p){
		 p=s*w;
		w++;		
		a-=p;
		if(a==0){
			cout<<w;
			break;
	}
else if(a<0){
			cout<<w-1;
			break;
		}
	}
	
	
	return 0;
}
 
 
