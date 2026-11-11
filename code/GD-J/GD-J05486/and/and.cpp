#include<bits/stdc++.h>
using namespace std;

long long n,m,mx=-1;
int s[200005];
string x;
long long b (string u ){
//	string k;
//	char p;
//	long long l=c.size();
//	if(l%2==0){
//		p=c[l/2];
//	}else{
//		p=c[l/2+1];
//	}
//	for(int i=0;i<p;i++){
//		
//	}
}
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>s[i]; 
	}
	sort(s+1,s+n+1); 
	mx=s[n];
	for(int i=n-1;i>=n-m+1;i--){
		 mx=(s[i]&mx);
	}
	cout<<mx;
}
