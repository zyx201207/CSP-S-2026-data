#include<bits/stdc++.h>
using namespace std;
string a;
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	long long z=0;
	while(n--){
		int num;
		char cnt;
		cin>>num>>cnt;
		for(long long i=z;i<z+num;i++){
			a[i]=cnt;
		}
		z+=num;
	}
	long long s;
	if(z%2==0){
		s=z/2;
	}
	else{
		s=z/2+1;
	}
	long long ans=0;
	for(long long i=s;i<z;i++){
		if(a[i-s]!=a[i]){
			ans++;
		}
	}
	cout<<ans;

	return 0;
}
