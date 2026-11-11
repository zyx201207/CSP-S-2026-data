#include<iostream>
#include<cstdio>
using namespace std;
int n,x,cnt=0,s=0;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>b;
		s+=x;
		for(int i=1;i<=x;i++) a+=b;		
	}
	for(int i=0;i<=s;i++){
		if(a[i]!=a[s-i-1]){
			a[i]=a[s-i-1];
			cnt++;
		} 
	}
	cnt-=1;
	cout<<cnt;
	return 0;
}
