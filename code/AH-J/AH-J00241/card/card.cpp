#include<bits/stdc++.h>
using namespace std;
int n,m,a[110000];
string s;
map<char,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=s.find(char(a[i]+48));
		if(b==-1){
			s+=char(a[i]+48);
		}else{
			s.erase(b,n-b);
			s+=char(a[i]+48);
		}
	}
	for(int j=0;j<s.size();j++){
		mp[s[j]]++;
	}
	for(int i=2;i<=n;i++){
		s.erase(0,s.size());
		for(int j=i;j<=n;j++){
			int b=s.find(char(a[j]+48));
			if(b==-1){
				s+=char(a[j]+48);
			}else{
				s.erase(b,n-b);
				s+=char(a[j]+48);
			}
		}
		for(int j=0;j<s.size();j++){
			mp[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[char(i+48)]<<" ";
	}
	return 0;
}
