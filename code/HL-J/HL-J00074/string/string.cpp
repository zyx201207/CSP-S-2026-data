#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,a,c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long h=0;
	for(int i=1;i<=n;i++){
		h+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=h;j++){
			if(a[i]!=0){
				s[j]=c[i];
				a[i]--;
			}
		}
	}
	if(n<=1){
		cout<<"0";
	}
	else{
		if(n<=2&&c[1]==c[2]){
			cout<<"0";
		}
		else if(n<=2){
			cout<<"1";
		}
		else{
			cout<<a[0];
		}
	}
	return 0;
}
