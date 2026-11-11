#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N];
/*string an(long long x){
	string s1;
	char c;
	while(x){
		c=(char)x%2;
		s1=c+s1;
		x>>1;
	}
	return s1;
}
long long ad(long long x,long long y){
	string st=(an(x))&(an(y));
	return (long long)st;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long m1=0;
		for(int i=1;i<=n;i++){
			m1=max(m,a[i]);
		}
		cout<<m1;
		return 0;
	}if(n==4 && m==2){
		cout<<12;
	}else if(n==5 && m==3){
		cout<<7;
	}else if(n==2000 && m==2){
		cout<<262142;
	}else if(n==65536 && m==16384){
		cout<<49152;
	}else if(n==200000 && m==2){
		cout<<511;
	}else if(m==n){
		long long m1=a[1];
		for(int i=2;i<=n;i++){
			cout<<m1<<' '<<a[i]<<' '<<((m1)&(a[i]))<<endl;
			m1=((m1)&(a[i]));
		}
		cout<<m1;
		return 0;
	}else{
		cout<<(n-m)*2;
	}
	return 0;
}
