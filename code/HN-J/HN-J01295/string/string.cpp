#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long l,n;
	cin>>l;
	string k="";
	char m;
	for(int i=0;i<l;i++){
		cin>>n;
		cin.get();
		m=cin.get();
		for(int j=0;j<n;j++){
			k+=m;
		}
	}
	long long dn=0;
	for(int i=0;i<k.size()/2;i++){
		if(k[i]!=k[k.size()-i-1]){
			dn++;
		}
	}
	cout<<dn;
	return 0;
}
