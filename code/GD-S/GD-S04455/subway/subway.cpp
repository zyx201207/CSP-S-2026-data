#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[10005],k[10005],a[1005][1005],t[1005][1005],x[10005],y[10005],t1[10005],sum,sum1,po[10005];
long long x1,y1,x2,y2;
/*void s(long long x1,long long y1,long long x2,long long y2,long long sum){
	if(x1>n||x2>n||x1<=0||x2<=0||y1>k[x1]||y2>k[x2]||y1<=0||y2<=0||t[x1][y1]==0||t[x2][y2]==0){
		return ;
	}
	if(x1==x2&&y1==y2){
		sum1=sum;
		return ;
	}
	sum+=t[x1][y1];
	s(x1+1,y1,x2,y2,sum);
	s(x1-1,y1,x2,y2,sum);
}*/
void f(long long k1,long long k2){
	
	sum=w[k1]+w[k2];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			if(k1==a[i][j]){
				x1=i;
				y1=j;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			if(k2==a[i][j]){
				x2=i;
				y2=j;
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(long long i=1;i<=q;i++){
		int edg=1;
		cin>>x[i]>>y[i];
		f(x[i],y[i]);
		t1[i]+=w[x[i]]+w[y[i]];
		if(y1<y2){
			while(y1+edg<=y2){
				t1[i]+=t[x1][y1+edg];
				edg++;
			}
		}
	}
	cout<<endl;
	for(long long i=1;i<=q;i++){
		if(i<q){
			cout<<t1[i]<<endl;
		}
		else{
			cout<<t1[i];
		}
	}
	
	return 0;
}
