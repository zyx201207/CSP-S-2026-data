#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string b="";
	int n,a,e,f=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++){
			b+=c;
		}
	}
	e=b.size();
	if(e%2==0){
		for(int i=0,j=e-1;i<=e/2-1&&j>=e/2;i++,j--){
			if(b[i]!=b[j])f++;
		}
	}
	else{
		for(int i=0,j=e-1;i<=e/2-1&&j>=e/2+1;i++,j--){
			if(b[i]!=b[j])f++;
		}
	}
	cout<<f;
	return 0;
}
