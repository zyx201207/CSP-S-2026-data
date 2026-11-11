//GZ-J00179 遵义市红花岗区第十三小学 郭璟岩
#include <bits/stdc++.h>
using namespace std;
long long h(string v){
	long long m=v.size();
	long long sum=0;
	for(long long i=0;i<=v.size()/2-1;i++){
		if(v[i]!=v[v.size()-i-1]){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
		}
	}
	cout<<h(s);
	return 0;
}

