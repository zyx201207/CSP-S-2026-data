#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int num[10005];
	char a[10005];
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(num[i]==num[i+2]&&a[i]==a[i+2]){
			cout<<0;
		}
	}
	bool x=1;
	int d=1;
	while(d<=n){
		if(a[1]==a[d]) d++;
		else x=0;
	}
	if(x!=0) cout<<0;
	return 0;
}

