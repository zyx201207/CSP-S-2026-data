#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,m,k,l;
string s;
char b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		k=a;
		m+=a;
		while(k--){
			s+=b;
		}
	}
	for(int i=0,j=m-1;i<m/2,j>=m/2+1;i++,j--){
		if(s[i]==s[j]){
			l++;
		}
	}
	cout<<m/2-l;
	return 0;
} 


