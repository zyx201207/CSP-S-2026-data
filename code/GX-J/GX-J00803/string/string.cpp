#include<bits/stdc++.h>
using namespace std;

int n,a,k=1,s=0;
char l[30000000],c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			l[k]=c;
			k++;
		}
	}
	
	k--;
	
	for(int i=1;i<=k/2;i++){
		if(l[i]!=l[k-i+1]) s++;
	}
	
	
	cout<<s;
	
	
	
	return 0;
}
