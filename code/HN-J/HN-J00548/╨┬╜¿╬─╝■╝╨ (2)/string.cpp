#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string1.out","w",stdout);
	double d,a;
	double cnt=0;
	cin>>d;
	string c,s;
	for(int i=0;i<d;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){		
			s[s.size()-1-i]=s[i];

			cnt++;
		}
	}	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
