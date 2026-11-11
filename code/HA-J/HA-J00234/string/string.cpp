#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
char a;
char b[200000000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=l;j<=l+m;j++){
			b[j]=a;
		}
		l+=m;
	}
	m=0;
	for(int i=1;i<=l/2;i++){
		if(b[i]!=b[l-i+1]){
			//cout<<b[i]<<' '<<b[l-i+1]<<endl;
			m++;
		}
	}
	cout<<m;
	return 0;
}
