#include<bits/stdc++.h>
using namespace std;
long long n,m,o,p,s,q[100000010],t,k,l;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>s>>c;
		for(int i=l;i<=l+s;i++){
			q[i]=c;
		}
		l+=s;
	}
	m=l/2;
	for(int i=1;i<=m;i++){
		if(q[i]!=q[l-i+1]){
			k+=1;
		}
	}
	cout<<k;
	return 0;
}
