#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s,s1;
	long long num=0;
	
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	int m=s.size();
	for(int i=m-1;i>=0;i--){
		s1+=s[i];
	}
	cout<<s<<endl;
	cout<<s1<<endl;
	for(int i=0;i<m/2;i++){
		if(s[i]!=s1[i]){
			num++;
		}
	}
	cout<<num; 
	return 0;
}
