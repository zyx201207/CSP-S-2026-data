#include<bits/stdc++.h>
using namespace std;
char s[1000000001];
int main(){
	int m,a,x=0;
	char c;
//	cin>>m;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=0;i<m;i++){
//		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[x]=c;
			x++;
		}
	}
	int z=0;
	for(int i=0;i<(x+1)/2;i++){
		if(s[i]!=s[x-1-i]){
			z++;
		}
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
