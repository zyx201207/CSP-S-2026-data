#include <bits/stdc++.h>
using namespace std;
long long a[200000],sum,num;
char c[200000];
string b;
int main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			b+=c[i];
		}
	}
	for(int i=0;i<sum/2;i++){
		if(b[i]!=b[n-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
