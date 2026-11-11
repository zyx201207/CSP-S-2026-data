#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	int  n,c=0,ci=0;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ci;
		c=c+ci;;
		
		cin>>s2;
		for(int j=0;j<ci;j++){
			s1=s1+s2;
		}
		ci=0;
	}
	ci=0;
//	cout<<s1<<' '<<c;
/////////////////////
	for(int i=0;i<(c/2);i++){
		if(s1[i]!=s1[c-i-1]){
			ci++;
			
		}
	//	cout<<s1[i]<<' '<<s1[c-i-1]<<"\n";
	}
	cout<<ci;
	return 0;
}
