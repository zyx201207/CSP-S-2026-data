#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],b[200010],d[100000005],e=1,f;
char c;
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c;
		b[i]=c-'a';
		for(int j=e;j<e+a[i];j++){
			d[j]=b[i];
		}
		e+=a[i];
	} 
	for(int i=1;i*2<=e;i++){
		if(d[i]!=d[e-i]){
			f++;
		}
	}
	cout<<f;
	return 0;
}

