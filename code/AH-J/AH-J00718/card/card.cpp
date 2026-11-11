#include<bits/stdc++.h>
using namespace std;
long long n,m,c,id;
char a[500010];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s=s+a[1];
	c=1;
	while(!s.empty()){
		c++;
		if(s.size()==1){
			id++;
			if(s[0]==m){
				cout<<id<<" ";
			}
		}
		for(int i=0;i<s.size();i++){
			if(s[i]==a[c%n+1]){
				s.erase(i,s.size()-1);
			}
		}
		s=s+a[c%n+1];
	}
	return 0;
}
