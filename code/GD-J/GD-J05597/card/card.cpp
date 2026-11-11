#include<bits/stdc++.h>
using namespace std;
int a,s;

int d[100000],f[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>s;
	for(int i =0; i<a;i++){
		cin>>d[i]; 
	}
	for(int i =0;i<a;i++){
		f[d[i]]=a-i;
	}
	for (int i=1;i<=s;i++){
		cout<<f[i]<<" ";
	}
	return 0;
} 
