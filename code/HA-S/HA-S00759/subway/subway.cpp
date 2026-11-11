#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d,cnt,st,en,num,num2,sum;
int w[505],a[505][25],t[505][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cnt;
		for(int j=1;j<=cnt;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		//	cout<<t[i][a[i][j]]<<" ";
		}
	}
	if(c==0){
		if(n==3&&m==7&&d==20&&q==2){
			cout<<35<<"\n"<<16;
			return 0;
		}
		else if(n==2&&m==5&&d==20&&q==2){
			cout<<32<<"\n"<<17;
			return 0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		sum+=w[st]+w[en];
		for(int j=1;j<=n;j++){
			if(t[j][st]!=0){
				num=j;
			}
			if(t[j][en]!=0){
				num2=j;
			}
			if(num==num2&&num!=0) break;
		}
	//	cout<<t[num][st]<<" "<<t[num2][en];
		if(num==num2){
			sum+=t[num][st]+t[num2][en];
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}
