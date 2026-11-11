#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	string c,ac;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(long long j=0;j<a;j++){
			ac+=c;
		}
	}
	if(ac[ac.size()/2-1]==ac[ac.size()/2]){
		cout<<"0";
		return 0;
	}
	cout<<ac.size()/2;
	return 0;
}
