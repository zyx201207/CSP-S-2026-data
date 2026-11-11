#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int m,n[100005];
char a[1010001];
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n[i];
		gets(a);
	}
	if(m==1){
		cout<<'0';
	}
	if(m==2){
		if(a[0]!=a[1]){
			if(n[1]>=n[2]){
				cout<<n[2];
			}
			else cout<<n[1];
		}
		else cout<<'0';
	}
	return 0;
}