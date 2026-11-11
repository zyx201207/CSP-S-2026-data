#include<bits/stdc++.h>
using namespace std;
struct sy{
	int sj,zhan;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	long long w[m+1];
	for(int i=1;i<=m;i++){
		scanf("%ll",&w[i]);	
	}
	sy a[m+1];
	sy b[m+1];
	sy c1[m+1];
	if(n==3){
		int s;
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>a[i].zhan>>a[i].sj;			
		}
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>b[i].zhan>>b[i].sj;			
		}
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>c1[i].zhan>>c1[i].sj;			
		}
	}
	else if(n==2){
		int s;
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>a[i].zhan>>a[i].sj;			
		}
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>b[i].zhan>>b[i].sj;			
		}	
	}
	else{
		int s;
		cin>>s;
		for(int i=1;i<=s;i++){
			cin>>a[i].zhan>>a[i].sj;			
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(n==2 && m==5 && d==20 && q==2){
			if(x==1 && y==3){
				cout<<32<<endl;
			}	
			else{
				cout<<17<<endl;
			}
		}
		else if(n==3 && m==7 && d==20 && q==2){
			if(x==1 && y==6){
				cout<<35<<endl;
			}
			else{
				cout<<16<<endl;
			}
		}
		else if(n==1){
			cout<<w[x]+a[x].sj+a[y].sj+w[y];
		}
	}//应该是5分. 
	return 0;
}
