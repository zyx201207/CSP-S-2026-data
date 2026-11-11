#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],c=0,d=0;
	string s,b;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b;
		for(int j=0;j<a[i];j++){
			s+=b;
		} 
	}
	for(int i=0;i<s.size();i++){
		int j=s.size()-1;
		if(s[i]!=s[j]){
			c++;
			s[j]=s[i];
		}
		j--;
	}
	for(int i=0;i<s.size();i++){
		int j=s.size()-1;
		if(s[i]!=s[j]){
			d++;
			s[j]=s[i];
		}
		j--;
	}
	cout<<min(c,d); 
	return 0;
}
