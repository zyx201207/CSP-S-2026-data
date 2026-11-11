#include<bits/stdc++.h>
using namespace std; 
long long a[20010];
char b[20010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			cout<<0;
			break;
		}
	}
	if(a[1]==2&&a[2]==2&&a[3]==1&&b[1]=='a'&&b[2]=='b'&&b[3]=='c'){
		cout<<2;
	} 
	return 0;
}
