#include<bits/stdc++.h>
using namespace std;
long long n,m;
int sum;
int cmd(long long q,long long w){
	return q<w;
}
long long a[500001],c[500001],qz[500001],qzc[500001],qzcc[500001],x,wc,A,B,B1,h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmd);
	B1=a[2]-a[1];
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]==B1)B++;
		qzc[i]=qzc[i-1]+c[i];
		qzcc[i]=qzc[i]+qzcc[i-1];
		qz[i]=c[i]*(i-1)+qz[i-1];
		A+=c[i];
//		cout<<c[i]<<" "<<qz[i]<<" "<<qzc[i]<<" "<<qzcc[i]<<endl;
	}
	if(A==0){
		if(m%n==0){
			sum=n;
		}
		else sum=n-1;
	}
	else if(B==n-1){
		int i;
		for(i=2;i<=n and h<=m;i++){
			h+=(i-1)*B1;
		}
		if(h>m)sum=i-1;
		else sum=i;
		if(m%sum!=0){
			sum--;
		}
	
	}
	else{
		for(int i=1;i<=n;i++){
			if(i+sum>=n)break;
			for(int j=i+sum;j<=n;j++){
				wc=j-i+1;
				x=qz[j]-(i-1)*qzc[j]+qzcc[i-1];
	//			cout<<i<<" "<<" "<<j<<" "<<x<<endl;
				if(m>=x){
					if(wc==n){
					
					if((m-x)%wc==0)sum=max(sum,int(wc));
					else sum=max(sum,(int)wc-1);
				}
					else{
						sum=max(sum,int(wc));
				}
				}
				else break;
			}
		}
	}
	cout<<sum;
	return 0;
}
