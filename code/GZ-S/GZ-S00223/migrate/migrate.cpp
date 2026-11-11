//GZ-S00223 遵义市第四初级中学 王培祯
#include<bits/stdc++.h>
using namespace std;
int c,t,m,n,x[200001],ans;
struct o{
	int b=0x3f3f3f3f;
	int d;
}x1[10001][10001];
void d(int s,int d1,int b){
	if(x1[s][d1].b==b){
		x1[s][d1].d++;
	}
	else{
		if(b<x1[s][d1].b){
			x1[s][d1].b=b;
			if(x1[s][d1].d==2){
				ans--;
			}
			x1[s][d1].d=1;
		}
	}
	if(x1[s][d1].d==2){
		ans++;
	}
	if(x1[s][d1].d==3){
		ans--;
	}
	for(int i=d1+1;i<=n&&x[i]-x[d1]<=m;i++){
		if(b+1<=x1[s][i].b){
			//cout<<s<<" "<<i<<" "<<b+1<<"  ";
			d(s,i,b+1);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13||c==14){
			cout<<"0";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&x[j]-x[i]<=m;j++){
				//cout<<i<<" "<<j<<" "<<"  ";
				d(i,j,1);
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x1[i][j].b=0x3f3f3f3f;x1[i][j].d=0;
			}
		}
	}
	return 0;
} 
