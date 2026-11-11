//GZ-J00130 凤冈县第二中学 罗迎甲 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long n,a[10000001]={},s;
	char c[10000001]={};
	string a1;
	cin>>n;
	for(int i=0;i<n;i++){
		string c;
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
		a1+=c;
	}
	}
	for(int i=0;i<(a1.size()-1)/2;i++){
		if(a[i]!=a[a1.size()-1-i]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
