#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	unsigned long long n;
	long long m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];}
	sort(a+1,a+n+1);
	long long b[n+1];
	b[1]=0;
	b[0]=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1]);
		}
	int ii;
	long long f=0;
	for(unsigned long long i=n;i>=2;i--){
		//cout<<"  +   ";
		long long j=0,k=0;
		while(k<m){
			k+=b[i]-b[i-j];
			j++;
			//cout<<k<<" ";
			if(i-j<=0) {
			break;	}}
		if(k!=m)
			j-=1;
//		if(f<j)
//			ii=i;
		f=max(f,j);
		
			}
	cout<<f;
	//Oct31==Dec25?
	return 0;
}
