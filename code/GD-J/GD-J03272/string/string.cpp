#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,a1;
	int n,js=0,js1=0,s=0;
	cin>>n; 
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		char t;
		cin>>t;
		for(int j=0;j<c;j++){
			a+=t;
			a1+=t;
			js++;
		}
	}
	reverse(a1.begin(),a1.end());
	while(a!=a1){
		if(a[js-1]!=a[js1]){
			a[js-1]=a[js1];
			a1[js1]=a[js-1];
			s++;
		} 
		js--;
		js1++;
	}
	cout<<s;
	return 0;
}
