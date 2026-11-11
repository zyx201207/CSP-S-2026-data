#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
int c(long long cu){
	long long cnt=0;
	for(int i=1;i<=cu;i++){
		cnt+=a[cu]-a[i];
	}
	if(cnt<=m){
		return 1;
	}
	if(cu==n)return 0;
	for(int r=cu+1,l=2;r<=n;r++,l++){
		cnt-=a[r-1]-a[l-1];
		cnt+=(a[r]-a[r-1])*(cu-1);
		if(cnt<=m)return 1;
	}
//	for(int i=cu;i<=n;i++){
//		cnt=0;
//		for(int j=i-cu+1;j<=i;j++){
//			cnt+=a[i]-a[j];
//		}
//		if(cnt<=m)return 1;
//	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
	long long p=1,l=0;
	while(p){
		if(l+p<=n&&c(l+p)){
			l+=p;
			p*=2;
		}
		else p/=2;
		//cout<<c(l)<<" "<<l<<endl;;
	}
	cout<<l;
	//cout<<endl<<c(3);
	return 0;
} 
//5 8
//-3 -1 2 2 7
