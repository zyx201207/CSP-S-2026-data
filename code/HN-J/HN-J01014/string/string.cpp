#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long j;
	char b;
	string a;
	for(int i=1;i<=n;i++){
		cin>>j>>b;
		for(int x=1;x<=j;x++){
			a+=b;
		}
	}
	long long t=a.size()-1;
	long long num=0;
	for(int i=0;i<=t/2;i++){
		if(a[i]!=a[t-i]){
			a[i]=a[t-i];
			num++;
		}
	}
	cout<<num;
	return 0;
}
