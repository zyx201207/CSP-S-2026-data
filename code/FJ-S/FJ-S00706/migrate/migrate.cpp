#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int h[5005][5005][2];
void pd(int x,int xx,int sum){
	if(h[x][xx][0]>sum){
		h[x][xx][0]=sum;
		h[x][xx][1]=1;
	}else if(h[x][xx][0]==sum){
		h[x][xx][1]++;
	}else{
		return;
	}
	if(xx>=n){
		return;
	}
	for(int i=xx;i<=n;i++){
		if(a[i]-a[xx]>d){
			break;
		}
		pd(x,i,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=5001;i++){
			for(int j=1;j<=5001;j++){
				h[i][j][0]=1e9;
				h[i][j][1]=0;
			}
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool flag=0,x=a[2]-a[1];
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=x){
				flag=1;
				break;
			}
		}
		if(!flag){
			if(d>=x*2&&d<x*3){
				cout<<n-3<<"\n";
			}else{
				cout<<"0\n";
			}
		}else{
			for(int i=1;i<=n;i++){
				pd(i,i,0);
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(h[i][j][1]==2){
						cnt++;
					}
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}
