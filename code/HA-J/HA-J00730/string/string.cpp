#include <bits/stdc++.h>
using namespace std;
const int N=1e9+2;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int q=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[q]=c;
			q++;
		}
	}
	int o=0,l=1,h=q-1;
	while(l!=h){
		if(s[l]!=s[h]){
			s[h]=s[l];
			o++;
		}
		l++;
		h--;
	}
	cout<<o;
	return 0;
}
