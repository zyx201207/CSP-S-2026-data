#include<bits/stdc++.h>
using namespace std;
struct String{
	long long a;
	char c;
}s[1e9];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s[i].c==s[j].c){
				cout<<0;
			}
		}
	}
}
