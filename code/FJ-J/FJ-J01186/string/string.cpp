#include<bits/stdc++.h>
using namespace std;
int n;
char b[200005];
string s;
long long sum=0,k=0,a[200005];
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[n+1-i]){
			k++;
		}
	}
	cout<<k;
	return 0;
}
