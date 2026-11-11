#include <bits/stdc++.h>
using namespace std;
string s,c;
int n,a;
int num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		if(a==1){
			cout<<0;
			return 0;
		}
		else{
			int k=s.size()-1;
		for(int i=0;i<=s.size();i++){
			if(s[i]!=s[k]){
				s[i]=s[k];
				num++;
			}
			if(i>=k){
				break;
			}
			k--;
		}
		cout<<num;
		}
	}
	while(n--){
		cin>>a>>c;
		s+=c;
		for(int i=1;i<a;i++){
			s+=c;
		}
		int k=s.size()-1;
		for(int i=0;i<=s.size();i++){
			if(s[i]!=s[k]){
				s[i]=s[k];
				num++;
			}
			if(i>=k){
				break;
			}
			k--;
		}
	}
	cout<<num;
	return 0;
}
