#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
char b;
string ans;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b; 
		for(int j=1;j<=a;j++){
			ans+=b;
		}
	}
	int c=0,j=n;
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[j]) c++;
		j--;
	}
	cout<<c;
	return 0;
	fclose("stdin");
	fclose("stdout");
}

