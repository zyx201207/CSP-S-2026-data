#include<bits/stdc++.h>
using namespace std;
int a,n,ans;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		for(int d=k;d<k+a;d++){
			s[d]=b;
		}
		k+=a;
	}
	for(int i=0;i<k/2;i++){
		if(s[i]!=s[k-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
