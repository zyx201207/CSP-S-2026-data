#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	long long sum=0;
	cin>>T;
	while(T--){
		long long n;
		char a;
		cin>>n>>a;
		sum+=n;
	}
	cout<<sum/2;
	return 0;
}
