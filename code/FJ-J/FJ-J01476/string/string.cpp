#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	int n,m=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,j=0;
		char c;
		cin>>a>>c;
		m+=a;
		while(a){
			s[j]=c;
			j++;
			a--;
		}
	}
	int x=0;
	for(int i=0;i<m;i++){
		if(s[i]!=s[m-i-1]){
			x++;	
		}
	}
	cout<<x/2;
	return 0;
}