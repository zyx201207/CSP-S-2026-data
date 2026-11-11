#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>m;
		char a;
		cin>>a;
		for(int j=0;j<m;j++){
			s+=a;
		}
	}
	for(int i=0;i<s.size()/2;i){
		for(int j=s.size()-1;j>=s.size()/2;j){
			if(s[i]!=s[j]){
				cnt++;
			}
			i++;
			j--;
		}
	}
	cout<<cnt;
	return 0;
} 

