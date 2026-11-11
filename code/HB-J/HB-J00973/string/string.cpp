#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long q=0,o=0;
    cin>>n;
    int f[n+1];
    char s[n+1];
    for(int i=1;i<=n;i++){
		int z;
		char x;
		cin>>z>>x;
		q=q+z;
		f[i]=z;
		s[i]=x;
	}
	char d[q+1];
	int y=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=f[i];j++){
			d[y]=s[i];
			y++;
		}
	}
	for(int i=1;i<=q/2;i++){
		if(d[i]!=d[q+1-i]){
			o++;
		}
	}
	cout<<o;
    return 0;
}
