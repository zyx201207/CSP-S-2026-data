#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",strin);
	freopen("string.out","w",strout);
	int n;cin>>n;
	bool f=1;
	while(n){
		long long x;char y;cin>>x>>y;
		if(a.size()!=0 and y!=a[a.size()-1])f=0;
		while(x){
			a+=y;
			x--;
		}
		n--;
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0;i<=(a.size()-1)/2;i++){
		//cout<<a[i]<<' '<<a[a.size()-1-i]<<endl;
		if(a[i]!=a[a.size()-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
} 
