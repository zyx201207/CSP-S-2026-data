#include<bits/stdc++.h>
using namespace std;
long long n,as,ans=0,cnt;
string a="0",y;
string xf(string m,long long ms){
	string n=m;
	for(long long i=0;i<ms;i++){
		n[i]=m[ms-i-1];
	}
	return n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long k;
		string j1;
		cin>>k;
		cin>>j1;
		for(long long j=1;j<=k;j++)a+=j1,as++;
	}
	for(long long i=1;i<=as;i++){
		for(long long j=i+1;j<=as+1;j++){
			if(j==i)y=a[i];
			else y=a.substr(i,j-i);
			if(xf(y,j-i)==y){
				if(j-i>ans)ans=j-i;
			}
		}
	}
	cout<<as-ans;
	return 0;
}
