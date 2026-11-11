#include<bits/stdc++.h>
using namespace std;
int a[1100];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=-1,ans=0;
	cin>>n;
	while(n--){
		int m;
		char ch;
		cin>>m>>ch;
		for(int i=1;i<=m;i++){
			s+=ch;
		}
		l+=m;
	}
//	cout<<s<<endl;
	for(int i=0;i<l/2;i++){
//		cout<<s[i]<<" "<<s[l+1-i]<<endl; 
		if(s[i]!=s[l-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return  0;
}
