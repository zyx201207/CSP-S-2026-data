#include<bits/stdc++.h>
using namespace std;
long long crystal[600000],dp[600000],c2=-1;
long long sss(long long crystal[600000],int n){
	int mmax=1,tmax=1;
	for(int i=0;i<n;i++){
		if(crystal[i]==crystal[i+1]){
			tmax++;
			if(tmax>mmax){
				c2=i;
				mmax=tmax;
			}
		}
		else{
			tmax=1;
		}
	}
	return mmax;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>crystal[i];
		dp[i]=crystal[i];
	}
	sort(crystal,crystal+n);
	long long mmax=1;
	mmax=max(mmax,sss(crystal,n));
	int x=0;
	if(sss(crystal,n)==1&&!((crystal[n-1]*2)<=m)){
		x=n-1/2;
		if(abs(crystal[x]-crystal[x-1])>n) x-1;
		
	}else if(!((crystal[n-1]*2)<=m)){
		x=c2+1;//-sss(crystal,n);
		cout<<"B ";
	}
	else{
		x=n-1;
	}
	for(int i=0;i<=x;i++){
		m-=crystal[x]-crystal[i];
		
		if(m<0){
			s--;
			break;
		}
		
		
		s++;
	}	
			
			
	cout<<s;//" "<<sss(crystal,n)<<" "<<x<<" "<<c2;
	return 0;
} 
