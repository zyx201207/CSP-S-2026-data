#include<bits/stdc++.h>
using namespace std;
string s="";
int L=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		int a;
		char c;
		cin>>a>>c;
		L+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}	
	}/*ÊäÈë×Ö·û´®s*/ 
	
	
	
	int l=L/2;/*°ë¸ö×Ö·û´®µÄ³¤¶È*/ 
	string x="";
	for(int i=L-1;i>L-l-1;i--){
		x+=s[i];
	}
	string y="";
	for(int i=0;i<l;i++){
		y+=s[i];
	}
	for(int i=0;i<l;i++){
		if(x[i]!=y[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
 }
 /*aabbc*/
