#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int b;cin>>b;
	int f=0;
	for(int i=0;i<b;i++){
		int c;char d;cin>>c>>d;
		int m=f;
		for(int j=m;j<m+c;j++){
			a[j]=d;
			f++;
		}
	}
	int sumn=0;
	for(int i=0;i<=ceil(f/2);i++){
		if(a[i]!=a[f-i-1]) sumn++;
	}
	cout<<sumn;
	return 0;
}
