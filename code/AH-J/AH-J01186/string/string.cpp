#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],m=0;
	char c[n];
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int l=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[l]=c[i];
			l++;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		for(int j=0;j<s.size();j++){
			if(s[j]!=s[s.size()-j-1]){
				break;
			}
			if(j==s.size()/2-1){
				cout<<m;
				return 0;
			}
		}
		s[i]=s[0];
		m++;
	}
	cout<<m;
	return 0;
}
