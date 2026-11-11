#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num;
	cin>>num;
	string all;
	all.clear();
	while(num--){
		long long a;
		char b;
		cin>>a>>b;
		for(long long i=0;i<a;i++){
			all+=b;
		}
	}
	long long len=all.size();
	string fhalf,bhalf;
	if(len%2==0){
		fhalf=all.substr(0,len/2);
		bhalf=all.substr(len/2,len/2);
		reverse(bhalf.begin(),bhalf.end());
	}else{
		fhalf=all.substr(0,len/2);
		bhalf=all.substr(len/2+1,len/2);
		reverse(bhalf.begin(),bhalf.end());		
	}
	long long cnt=0;
	for(long long i=0;i<len/2;i++){
		if(bhalf[i]!=fhalf[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
