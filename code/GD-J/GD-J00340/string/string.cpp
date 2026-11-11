#include<bits/stdc++.h>
using namespace std;
long long n,a[101],sum=0;
int main(){
	freopen("string.in","r"stdin);
	freopen("string.out","w"stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a[i];	
	}
	string(n);
	string a[1]=a[1]+1;
	for(int i=1;i<=n;i++){
		if(i<=a[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
