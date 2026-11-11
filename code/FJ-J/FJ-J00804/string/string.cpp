#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[200005];
char c[200005];
string s;
long long b;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	s+='a'; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		b+=a[i];
	}
	for(int i=1;i<=b/2;i++){
		if(s[i]!=s[b-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
} 
