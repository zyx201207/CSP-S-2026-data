#include<bits/stdc++.h>
using namespace std;
int c,t,n,num,a,sum;
long long d,x[2000005];
int blf(int l,int r,int s){
	if(l==r){
		if(s<sum){
			sum=s;
			a=1;
		}
		else if(s==sum){
			a++;
		}
		return 0;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			blf(i,r,s+1);
		}else{
			break;
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int tt=0;tt<t;tt++){
		cin>>n>>d;
		num=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(d>=x[n-1]-x[0]||n<=3){
			cout<<num;
			if(tt<t-1)cout<<endl;
		}else{
			for(int i=0;i<n-3;i++){
				for(int j=i+3;j<n;j++){
					if(x[j]-x[i]<=d)break;
					a=0;
					sum=n;
					blf(i,j,0);
					if(a==2)num++;
				}
			}
			cout<<num;
			if(tt<t-1)cout<<endl;
		}
	}
	
	return 0;
	
}
