#include<bits/stdc++.h>
using namespace std;
struct noid{
	long long a1;
	string a2;
}a[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int f=0,f1=1;
	long long t=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2;
		t+=a[i].a1;
		if(a[i].a2==a[i-1].a2 && f1){
			f=1;
		}
		else{
			f=0;
			f1=0;
		}
	}
	t/=2;
	if(f){
		cout<<0;
		return 0;
	}
	cout<<t;
	return 0;
}
