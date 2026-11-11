#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int num=0,mun=0;
	int n,a[1000005],c[1000005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num;j++){
			s[i]=c[i];
		}
	}
	for(int i=num;i>=1;i--){
		if(s[i-1]==a[num-1]){
			mun++;
		}
	}
	cout<<mun;                                                                  
	return 0;
}
