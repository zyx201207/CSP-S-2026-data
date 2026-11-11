#include<bits/stdc++.h>
using namespace std;
int n,m,k1,k2;
int b[33][200000];
int bz[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int zg(int k){
	int l=1,o=0;
	while(l=l<<1){
		if(l>k)
			return o;
		else
			o++;
	}
}
bool pd(int k4,int t){
	if((k4>>t)%2)return 1;
	return 0;
}
int fi(int bi,int ybi){
	int siz=0;
	if(bi==0){
		for(int i=0;i<bz[ybi];i++)
			siz+=b[ybi][i]%2;
		if(siz>=m)return 1;
		return 0;
	}
	for(int i=0;i<bz[ybi];i++)
		siz+=pd(b[ybi][i],bi);
	if(siz==m)return 1<<bi;
	if(siz>m)return (1<<bi)+fi(bi-1,ybi);
	if(siz<m)return fi(bi-1,ybi);
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k2;
		k1=zg(k2); 
		b[k1][bz[k1]++]=k2;
	}
	int i=31;
	while(i--){
		if(bz[i]==m){
			k1=b[i][0];
			for(int j:b[i])
				k1=k1&j;
			cout<<k1;
			return 0;
		}else if(bz[i]>m){
			cout<<fi(i,i);
			return 0;
		}
	}
	return 0;
}

