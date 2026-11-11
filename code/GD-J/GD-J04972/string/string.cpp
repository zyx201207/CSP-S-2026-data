#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,w1,co=0,sum=0;
	string z,w2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w1>>w2;
		for(int i=1;i<=w1;i++) z+=w2;
		co+=w1;
	}
	for(int i=0;i<co/2;i++){
		if(z[i]!=z[co-i-1]){
			sum++;
		}
	}
	cout<<sum;
	
	return 0;
}
