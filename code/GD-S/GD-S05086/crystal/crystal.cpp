#include<bits/stdc++.h> 
using namespace std;
const int N=1000005;
long long n,m,a[N],b[N],ma=0,noma=1,now=0;
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		b[i] = a[i+1] - a[i];
		//cout<<b[i]<<endl;
	}
	for(long long i=1,j=1;i<=n;i++){
		//printf("%d %d %d %d\n",&b[i],&now,&noma,&ma);
		if(b[i]>m){
			if(noma>ma) ma=noma;
			break;
		}
		if(now+b[i]<=m) now+=b[i],noma++;
		else {
			if(noma>ma) ma=noma;
			noma--,now-=b[j],j++;
		}
	}
	cout<<ma;
	return 0;
}
