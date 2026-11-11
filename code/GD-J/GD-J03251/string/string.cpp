#include<bits/stdc++.h>
using namespace std;
int n,a[200100],s;
char b[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n,x=1,y=1;i<j;){
		if(b[i]!=b[j])s++;
		x++,y++;
		if(x>a[i])i++,x=1;
		if(y>a[j])j--,y=1;
	}
	cout<<s;
	return 0;
}
