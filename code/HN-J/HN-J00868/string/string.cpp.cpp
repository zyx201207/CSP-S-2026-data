#include<bits/stdc++.h> 
using namespace std;
char a[2000001];
int n,x[2000001];
bool po=1,jk=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;return 0;
	}
	cin>>x[1]>>a[1];
	for(int i=2;i<=n;i++){
		cin>>x[i]>>a[i];
		if(a[i]!=a[i-1]){
			po=0;
		}
		if(x[i]!=x[i-1]){
			jk=0;
		}
	}
	if(po){
		cout<<0;return 0;
	}
	if(jk){
		if(n==2){
			cout<<x[1];return 0;
		}
	}
	return 0;
}
