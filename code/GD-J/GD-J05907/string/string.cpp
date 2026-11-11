#include<bits\stdc++.h>
using namespace std;
string L;
int n,m;
char x;
long long t,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>x;
		s+=m;
		for(int j=1;j<=m;j++){
			L+=x;
		}
	}
	for(int i=1;i<=s;i++){
		if(L[i]!=L[s-i+1]) t++;
	}
	cout<<t;
	return 0;
}
