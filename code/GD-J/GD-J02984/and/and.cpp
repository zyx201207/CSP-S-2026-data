#include<bits/stdc++.h> 
using namespace std;
long long an(long long x,long long y){
	string a1,a2,a;
	while(x!=0){
		a1+='0'+x%2;
		x/=2;
	}
	while(y!=0){
		a2+='0'+y%2;
		y/=2;
	}
	for(int i=a2.length()-1;i<a1.length()-1;i++){
		a2+='0';
	}
	for(int i=0;i<a1.length();i++){
		if(a1[i]=='1'&&a2[i]=='1'){
			a+='1';
		}
		else{
			a+='0';
		}
	}
	long long lz=1,llz=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1'){
			llz+=lz;
		}
		lz*=2;
	}
	return llz;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long sum=0;
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	for(int i=0;i<n-m+1;i++){
		for(int j=i+1;j<n-m+2;j++){
			long long ant=max(ant,an(max(a[i],a[j]),min(a[i],a[j])));
			for(int k=1;k<m-1;k++){
				ant=an(max(ant,a[j+k]),min(ant,a[j+k]));
			}
			sum=max(ant,sum);
		}
	}
	cout<<sum;
	return 0; 
}
