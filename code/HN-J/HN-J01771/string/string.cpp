#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s[k]=c;
			k++;
		}
	}
	int f=0;
	for(int i=k-1;i>=0;i--){
		s1[i]=s[f];
		f++;
	}
	bool b=true;
	for(int i=0;i<k;i++){
		if(s[i]!=s1[i]){
			b=false;
		}
	}
	if(b==true){
		cout<<"0";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
