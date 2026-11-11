#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0,k=0;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s1[k]=b;
			k++;
		}
	}
	for(int i=0;i<(k+1)/2;i++){
		if(s1[i]!=s1[k-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
