#include<bits/stdc++.h> 
using namespace std;
int n;
long long k,lenn=0,ans=0;
char a;
string b="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>k>>a;
		for(int j=0;j<k;j++){
			b+=a;
			lenn++;
		}
	}
	for(int i=0;i<lenn/2;i++){
		if(b[i]!=b[lenn-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
