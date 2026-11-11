#include<bits/stdc++.h>
using namespace std;
char s[100000]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int w=0;
	int len=0;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		len+=a;
		char q;
		cin>>q;
		for (int l=0;l<a;l++){
			s[w]=q;
			w++;
		}
	}
	int num=0;
	for (int x=0,y=len-1;x<y;x++,y--){
		if (s[x]!=s[y]){
			num++;
		}
	}
	cout<<num<<"\n";
	return 0;
}
