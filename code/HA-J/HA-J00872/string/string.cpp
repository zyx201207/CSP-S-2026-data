#include <bits/stdc++.h>
using namespace std;
long long n,a,he=0,gai=0,j=0,c=605;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char b;
	cin>>n;
	string s[c];
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		he+=a;
//		cout<<he<<endl;
		for(j=j+1-1;j<he;j++){
			s[j]+=b;
		}
		j=he;
	}
	he-=1;
	for(int i=0;i<he/2;i++){
		if(s[i]!=s[he-i]){
			gai+=1;
		}
	}
	cout<<gai;
	return 0;
} 
