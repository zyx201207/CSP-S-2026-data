#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,ci=0;
	cin>>n;
	char s;
	string m;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>s;
		for(int j=1;j<=x;j++){
			m=m+s;
		}
	}
	for(int i=0;i<=m.size()/2;i++){
		if(m[i]!=m[m.size()-i-1]){
		}
			ci++;
	}
	cout<<ci;
	return 0;
}
