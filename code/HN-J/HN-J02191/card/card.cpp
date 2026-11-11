#include<bits/stdc++.h> 
using namespace std;
int n,m;
int p[500005],a[300005],p2[500005];
int cf(int x,int y,int z){
	for(int i=x;i<=y;i++){
		if(p[i]==z){
			return i+1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		p2[i]=p[i];
	}
	for(int i=1;i<=m;i++){//局数 
		for(int j=i;j<=m;j++){//出的牌 
			int k=cf(i,j,p[j]);
			a[p2[j]]++;
			if(k!=0){
				for(int l=k;l<=j;l++){
					a[p2[l]]--;
					p2[l]=0;//防止重复减 
				}
			}
		}
		for(int i=1;i<=n;i++){
			p2[i]=p[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
