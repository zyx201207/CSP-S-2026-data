#include<bits/stdc++.h>
using namespace std;
int main(){
	long long m,o=0,cnt=0,j,n,i,b;
	char a;
	unsigned long long v[100000];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>m;
		cin>>a;
		b=int(a); 
		for(j=0;j<m;j++){
			v[o]=b;
			o++;
		}
	}
	for(i=0;i<o/2+1;i++){
		if(v[i]!=v[o-i-1])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
