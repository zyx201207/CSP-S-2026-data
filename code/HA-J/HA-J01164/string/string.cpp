#include<bits/stdc++.h>
using namespace std;
char l[100000005];
int f(int n){
	int ans=0;
	for(int i=0;i<n/2;i++){
		if(l[i]!=l[n-1-i]) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int d=0;
	long a;
	long long sum=0;
	for(int i=0;i<n;i++){
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			l[d]=b;
			d++;
		}
		sum+=a;
	}
	cout<<f(sum);
	return 0;
}
