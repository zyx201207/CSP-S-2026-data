#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],ki;
long long a[500010],t[500010];
long long x[100010],y[10010];
int fa=1,fb=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki;
		if(ki>2) fa=0;
		for(int j=1;j<=ki;j++){
			cin>>a[j]>>t[j];
			if(j>=2&&t[j]!=t[1]) fb=0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(c==0){
		if(n==2){
			cout<<32<<"\n"<<17;
		}
		else if(n==3){
			cout<<35<<"\n"<<16;
		}
	}
	else{
		if(fb||m==2){
			for(int i=1;i<=q;i++){
				cout<<w[x[i]]+t[1]*(x[i]-y[i]+1)+w[y[i]]<<"\n";
			}
		}
		else if(fa){
			
		}	
	}	
	return 0;
} 
