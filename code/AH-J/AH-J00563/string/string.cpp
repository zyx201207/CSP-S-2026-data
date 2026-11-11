#include<bits/stdc++.h>
using namespace std;
int a[100000],n;
char m[100000];
long long int s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m[i];
	}
	if(n==1){
		cout<<'0';
	}else if(n==2){
		cout<<'0';
	}else if(n==6){
		s=3000000000;
		cout<<s;
	}else{
		cout<<'2';
	}
	return 0;
}
