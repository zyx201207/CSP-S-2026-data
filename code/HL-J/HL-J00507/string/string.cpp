#include <bits/stdc++.h>
using namespace std;
int m,q;
char c;
string a,b;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>m>>c;
		for(int j=0;j<m;j++){
			a[q]=c;
		}
	}
	int w=0;
	for(int i=q;i>=1;i--){
		b[w]=a[i];
		w++;
	}
	int ans=0;
	for(int i=0;i<=q;i++){
		if(b[i]!=a[i]) ans++;
	}
	if(ans==0){
	cout<<0;	
	} else{
		cout <<2*m;
	}
	return 0;
}
