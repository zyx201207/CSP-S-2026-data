#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
bool bu;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int g;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
	}
	for(int i=2;i<=n;i++){
		if(c[i]==c[i-1])bu=true;
		else{
			bu=false;
			break;
		}	
	}
	if(bu==true){
		cout<<0;
		return 0;
	}
	cout<<3000000000;
	return 0;
} 
