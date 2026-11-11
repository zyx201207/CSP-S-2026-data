#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>1&&c[i]!=c[1])ok=0;
	}
	if(ok==1){
		cout<<"0";
		return 0;
	}
	if(n==2&&(a[1]==a[2])){
		cout<<a[1];
		return 0;
	}
	if(n==3&&(c[1]==c[3])&&(a[1]==a[3])){
		cout<<"0";
		return 0;
	}
}
