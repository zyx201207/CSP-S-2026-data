#include<bits/stdc++.h>
using namespace std;
int n;
int a[2005];
char b[2005];
string s;
bool check(string x){
	string y=x;
	reverse(x.begin(),x.end());
	if(y==x){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[j]=b[i];
		}
	}
	if(check(s)==true){
		cout<<0;
	}
	return 0;
}
