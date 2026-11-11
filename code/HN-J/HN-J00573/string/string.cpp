#include<bits/stdc++.h>
using namespace std;
string s;
long long maxx = -1;
long long n,sum1,sum2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		long long k;
		cin>>k;
		if(i==1) sum1 = k;
		if(i==2) sum2 = k;
		char a;
		cin>>a;
		maxx = max(maxx,k);
		while(k--) s+=a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<max(sum1,sum2)-min(sum1,sum2);
		return 0;
	}
	cout<<maxx;
	return 0;
}
