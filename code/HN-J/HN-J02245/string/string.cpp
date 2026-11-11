#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	frepoen(".in","r",stdin);
	frepoen(".out","w",stdout);
	cin>>n;
	int long long count=0,a[n];
	char  c[n];
	string s="";
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	char  m[s.size()/2];
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++){
			m[i]=s[i];
		}
		for(int i=s.size()-1;i>s.size()/2;i--){
			if(s[s.size()-1-i]!=m[i]){
				count++;
			}
		}
		cout<<count;
		return 0;
	}
	else{
		for(int i=0;i<s.size()/2;i++){
			m[i]=s[i];
		}
		for(int i=s.size()-1;i<s.size()/2;i--){
			if(s[s.size()-1-i]!=m[i]){
				count++;
			}
		}
		cout<<count;
		return 0;
	}
	return 0;
}
