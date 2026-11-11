#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,q=0,w=0;
	cin>>n;
	string c,s[100];
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[j]=c;
			w=w+a;
		}
	}
	for(int i=0;i<w;i++){
		if(s[i] != s[w-i-1]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
