#include<bits/stdc++.h>
using namespace std;
int n;
long long w=0;
long long ans=0;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char b;
		cin>>b;
		for(long long j=1;j<=a;j++){
			s1[w+j]=b;
		}
		w+=a;
	}
	long long mid=1+(w-1)/2;
	for(long long i=1;i<=mid;i++){
		if(s1[i]!=s1[w-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
