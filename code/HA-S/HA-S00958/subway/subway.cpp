#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,z,c,x,y;
long long a1,a2,a3,a4;
struct{
	int w;
	int t[20];
	int r[20];
}subway[500005]; 
int huancheng(long i,long to,long time,int e){
	if(i==to){
		return subway[i].t[e];
	}
	if(e==0){
		for(int i=0;i<n;i++){
			
		}
	}
	return min(huancheng (i+1,to,time),huancheng (i+1,to,time,2)+subway[i].t[e]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		cin>>subway[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=0;j<c;j++){
			cin>>a1>>a2;
			subway[a1].t[c]=a2;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<huancheng(x,y,subway[x].w+subway[x].w,0)<<endl;
	}
	return 0;
} 
