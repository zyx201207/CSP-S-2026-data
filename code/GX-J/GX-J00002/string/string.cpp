#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=2ef+5;
char c[N];
int z,n,j=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char s;
		cin>>a>>s;
		for(int i=j+1;i<=j+a;i++){
			c[i]=s;
		}
		j+=a;
	}
	for(int i=1;i<=n;i++){
		int y=j+1-i;
		if(c[i]!=c[y]){
			z++;
		}
	}
	cout<<z;
	return 0;
}
