#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long m,cnt=0;cin>>n;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			b+=a;
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]!=b[int(b.size())-i-1]){
			cnt++;
			b[i]=b[int(b.size())-i-1];
		}
	}
	cout<<cnt;
 return 0;
}