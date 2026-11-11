#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,ans;
	char s; 
	cin>>n;
	string si;
	for(int a=0;a<n;a++){
		cin>>i>>s;
		for(int a=0;a<i;a++){
			si.push_back(s);
		}
	}
	for(int c=0;c<n;c++){
		char o;
		if(si[c]!=si[si.size()-c+1]){
			o=si[c];
			si[si.size()-c+1]=o;
			ans+=1;
		}else{
			ans+=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
