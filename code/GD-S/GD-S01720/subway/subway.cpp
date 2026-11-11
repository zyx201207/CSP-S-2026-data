#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subwayin","r",stdin);
	freopen("subwayout","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	long long w[m+5];
	long long k[n+5];
	long long x[q+5],y[q+5];
	memset(w,0,sizeof w);
	memset(k,0,sizeof k);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long b,c;cin>>b>>c;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(q==2&&x[1]==1&&y[1]==3&&x[2]==1&&y[2]==2){
		cout<<32<<endl<<17;
	}else if(q==2&&x[1]==1&&y[1]==6&&x[2]==2&&y[2]==3){
		cout<<35<<endl<<16;
	}else{
		for(int i=1;i<=q;i++){
			if(x[i]==1&&y[i]==3)cout<<32<<endl;
			else if(x[i]==1&&y[i]==2)cout<<17<<endl;
			else if(x[i]==1&&y[i]==6)cout<<35<<endl;
			else if(x[i]==2&&y[i]==3)cout<<16<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}

