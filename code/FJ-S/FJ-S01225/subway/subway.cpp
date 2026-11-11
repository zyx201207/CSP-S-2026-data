#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[20001],k[501],a[501][500001],t[501][500001],x[100001],y[100001],ans[100001],mans=100000;
void func(int f,int k,int y){
	for(int j=1;j<=n&&j!=f;j++){
		for(int p=1;p<=k;p++){
			int l=a[j][p];
			for(int r=1;r<=k;r++){
				if(a[f][r]==l){
					if(l==y){
						mans=min(mans,t[f][r]+w[a[f][r]]);
					}
					else{
						func(j,k,y);
					}
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){			
			cin>>a[i][j]>>t[i][j];			
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		ans[i]+=w[x[i]];
		int minans=10000000,f;
		for(int j=1;j<=n;j++){
			for(int p=1;p<=k[j];p++){				
				if(a[j][p]==x[i]){
					if(t[j][p]<minans){
						minans=t[j][p];
						f=j;
					}
				} 
			}
		}
		ans[i]+=minans;
		int flag=0;
		for(int j=1;j<=k[i];j++){
			if(a[f][j]==y[i]){
				mans=min(mans,t[f][j]+w[a[f][j]]);
				flag=1;
			}
		}
		if(flag){
			ans[i]+=mans;
		}
		else{			
			func(f,k[i],y[i]);	
			ans[i]+=mans;
		}		
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
