#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2*1e5+3;
LL n,m,xj=1,b;
LL al[N][31],ak[N],a[N],num,mix,mx[N];
void bl(int dp){
	if(dp-1==m){
		return ;
	}
	mix=0;
	int xi;
	for(int j=1;j<=n;j++){
		if(a[j]==1) continue;
		int k=1;
		num=0;
		for(int z=1;z<=min(ak[xj],ak[j]);z++){
			if(al[xj][z]==1 && al[j][z]==1){
				num+=k;
			}
			k*=2;
		}
		if(num>mix){
			mix=num;
			xi=j;
		}
	}
	xj=xi;
	num=mix;
	int w=0;
	while(num){
		w++;
		al[xj][w]=num%2;
		num/=2;
	}
	ak[xj]=w;
	a[xj]=1;
	bl(dp+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>b;
		int w=0,num=0;
		while(b){
			w++;
			al[i][w]+=b%2;
			if(b%2==1) num++;
			b/=2;
		}
		if(num>x){
			x=num;
			xj=i;
		}
		ak[i]=w;
	}
	a[xj]=1;
	bl(2);
	cout<<mix;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
