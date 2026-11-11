#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005];
bool cmd(int x,int y){
	return x>y;
}
int f(int x,int y){
	long long sum=0;
	for(int i=x;i<=y;i++){
		sum+=(b[i]-b[x]);
	}
	return sum;
}
int main(){
	//*
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//*/
	cin>>n;
	cin>>m;
	b[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmd);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+a[i-1]-a[i];
		//cout<<b[i]<<" ";
	}
	//cout<<endl;
	long long mx=-1;
	for(int i=1;i<=n;i++){
		long long l=i,r=n;
		//cout<<"i="<<i<<endl;
		while(l<=r){
			int mid=(l+r)>>1;
			//if((l+r)%2==1)mid+=1;
			//cout<<l<<" "<<r<<" "<<mid<<endl;
			//cout<<"f : "<<f(i,mid)<<endl;
			if(f(i,mid)==m){
				l=mid+1;break;
			}
			if(f(i,mid)<m)l=mid+1;
			else r=mid-1;
		}
		//cout<<endl<<endl;
		//cout<<"max: "<<l-i<<endl;
		mx=max(mx,l-i);
	}
	cout<<mx;
	//* 
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
} 
/*
10 10
23 20 16 16 16 12 16 16 13 11

*/
