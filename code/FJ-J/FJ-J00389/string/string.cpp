#include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long a[200005];
long long m,num,b;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=1;
	num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=m;j<m+a[i];j++){
			s[j]=c[i];
		}
		m=m+a[i];
	}
	m=m-1;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}

