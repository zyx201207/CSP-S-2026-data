#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char b[N];
int n;
long long ans;
void solve1(){
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		} 
	}
	int m=s.size()-1;
	for(int i=0;i<=m/2;i++){
		if(s[i]!=s[m-i]){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	solve1();
	return 0;
}
