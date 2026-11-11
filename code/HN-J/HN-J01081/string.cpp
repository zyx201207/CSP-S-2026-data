#include<bits/stdc++.h>
using namespace std;
int n,l,cnt;
int  a[200005];
char c[200005];

char get(int k){
	int nl=0,i=1;
	while(k>nl && i<n){
		nl+=a[i];i++;
	}cout<<c[i]<<'\n';
	return c[i];
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		l+=a[i];
	}for(int i=1;i<=n;++i){
		if(get(i)!=get(l-i+1)) cnt++;
	}cout<<cnt<<'\n';
	return 0;
} 
