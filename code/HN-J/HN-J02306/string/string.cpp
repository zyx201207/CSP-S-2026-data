#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	long long a,l=0,gs=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(l%2==0){
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-i-1]){
				gs++;
			}
		}
	}
	else{
		for(int i=0;i<=l/2;i++){
			if(s[i]!=s[l-i-1]){
				gs++;
			}
		}
	}
	cout<<gs;
return 0;
}


