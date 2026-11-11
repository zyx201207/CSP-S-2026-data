#include<bits/stdc++.h>
using namespace std;
string c;
char s[200009];
int n,coust,bz=0,o=0,l;
long long a[200009];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		
		for(int j=bz;j<bz+a[i];j++){
			c[j]=s[i];
			
		}
		bz+=a[i];

	}

	for(int i=0;i<bz/2;i++){
		if(c[i]!=c[bz-1-i])coust+=1;
	}
	cout<<coust;
	
	return 0;
}
