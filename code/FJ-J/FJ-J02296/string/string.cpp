#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b;
	int d,e;
	d=0;
	e=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		cin>>c;
		for(int j=1;j<=b;j++){
			d++;
			a[d]=c;
		}
	}
	for(int i=1,j=d;i<=d&&j>=1;i++,j--){
		if(j<=i){
			break;
		}
		if(a[i]!=a[j]){
			e++;
		}
	}
	cout<<e<<endl;
	return 0;
} 
