#include<bits/stdc++.h>
using namespace std;
long long a[200005],y=1,ans;
int n,m,b[200005][33],c,maxx=-1,qd[200002];
void tba(int dzd,int zdz){
	int bbin=0;
	while(dzd>0){
		b[zdz][bbin++]=dzd%2;
		dzd=(dzd/2*2)/2;
	}
}void cho2(int yum[200003],int wow,int jy){
	int mus=wow;
	if(wow==m){
		for(int i=1;i<=wow;i++){
			qd[i]=yum[i];
		}
	}else{
		while(1){
			int sum=0;
			for(int i=1;i<=wow;i++){
				if(b[yum[i]][jy]==1){
					sum++;
				}
			}if(sum>=m){
				for(int i=1;i<=wow;i++){
					if(b[yum[i]][jy]==0){
						yum[i]=91917813;
						mus--;
					}
				}sort(yum+1,yum+wow+1);
				jy--;
				cho2(yum,mus,jy);
				break;
			}else if(jy==1){
				for(int j=1;j<=m;j++){
					qd[j]=yum[j];
				}break;
			}else jy-=1;
		}
	}
}void cho(int l){
	int t[200003],hhh=0;
	memset(t,0,sizeof(t));
	for(int q=1;q<=200003;q++){
		if(b[q][l]==1){
			t[++hhh]=q;
		}
	}
	cho2(t,hhh,l-1);
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int d[m+1];
	memset(d,0,sizeof(d));
	memset(b[200004],1,sizeof(b[200004]));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tba(a[i],i);
	}for(int i=31;i>=0;i--){
		for(int j=1;j<=200002;j++){
			c+=b[j][i];
		}if(c>=m){
			cho(i);
			break;
		}c=0;
	}for(int i=1;i<=m;i++){
		for(int j=0;j<=31;j++){
			b[200004][j]&=b[qd[i]][j];
		}
	}for(int i=0;i<=31;i++){
		ans+=b[200004][i]*y;
		y*=2;
	}cout<<ans;
	return 0;
} 
