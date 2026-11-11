#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sam=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=strlen(s)/2;i++){
		for(int j=strlen(s);j>=strlen(s)/2;j--){
			if(i!=j)sam++;
		}
	}
	cout<<sam;
}
