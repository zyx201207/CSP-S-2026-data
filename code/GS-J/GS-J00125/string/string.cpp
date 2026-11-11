#include <bits/stdc++.h>
using namespace std;
char e[200005];
long long a,c=0;
//int c=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		char b;
		cin>>b;
		//cout<<a<<" "<<b<<endl;
		for(int j=0;j<a;j++){
		e[m]=b;
		m++;
		}
	}
	long long c=0;
	int k=n;
	for(int j=0;j<n;j++){
		k--;
		if(e[j]==e[k]){
		}else{
			c++;
		}
		}cout<<c;
return 0;
}
