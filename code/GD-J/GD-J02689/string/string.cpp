#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		//cout<<1;
		int a;
		char c;
		string nw;		
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			nw=nw+c;
		}
		s=s+nw;
	//	cout<<s<<endl;
	}
//	cout<<s<<endl;
	int num=0;
	for(int i=0;i<s.size()/2+1;i++){
		if(s[i]!=s[n+1-i]){
			num++;
		}
	}
	cout<<num;	
} 
/*Trick||Treat!
*/
