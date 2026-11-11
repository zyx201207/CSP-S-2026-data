#include<bits/stdc++.h>
using namespace std;
int n,m;	
int cnt;
long long oi[200005];
long long o[200005][35];
long long ai[200005];
long long a[200005][35];
long long pifang(int num,int mi){
	long long neww_num=1;
	while(mi--){
		neww_num*=num;
	}
	return neww_num;
}
int ser(int key){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int cntt=0;
	if(key<0){
		int zhi=oi[1];
		for(int i=2;i<=m;i++){
			zhi=zhi&oi[i];
		}
		return zhi;
	}

	
								
	for(int i=1;i<=cnt;i++){
		if(o[i][key]){
			cntt++;
		}
		
	}
	if(cntt<m){
	return ser(key--);		
	}
	cntt=0;
	for(int i=1;i<=cnt;i++){
		if(o[i][key]){
			cntt++;
			oi[cntt]=oi[i];
			for(int ii=0;ii<=32;ii++){
				o[cntt][ii]=a[i][ii];
			}
		}
	}
	cnt=cntt;
	return ser(key--);
	
}
int main(){
	
	 cin>>n>>m;
	 cnt=n;
	 for(int i=1;i<=n;i++){
	 	cin>>ai[i];
	 	for(int j=0;j<=32;j++){
	 		a[i][j]=ai[i]&pifang(2,j);
		 }
	 	
	 }

	
	for(int i=1;i<=n;i++){
		oi[i]=ai[i];
		for(int ii=0;ii<=32;ii++){
			o[i][ii]=a[i][ii];
		}
	}
 	int ans=ser(32);
	cout<<ans;

	return 0;
}
