#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("string.in","r",stain);
	freopen("string.out","w",staout);
	int n;
	cin>>n;
	int s=0;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(n!=a[i]){
			s+=a[i];
		}
		cout<<s;
	}
	return 0;
}
