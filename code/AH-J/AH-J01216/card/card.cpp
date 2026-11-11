#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],x[300001]={},y[500001]={},t,xt=0;
int cf(int b){
	for(int i=1;i<=xt;i++){
		if(b==y[i]){
			for(int j=i;j<=xt;j++){
				y[j]=0;
			}
			xt-=i;
			return i;
		}
	}
	return xt+1;
}
void sj(){
	for(int i=1;i<=n;i++){
		x[y[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t=cf(a[j]);
			y[t]=a[j];
			xt++;
		}
		sj();
		for(int j=1;j<=xt;j++){
			y[j]=0;
		}
		xt=0;
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<' ';
	}
	return 0;
}
