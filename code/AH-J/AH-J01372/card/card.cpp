#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500001]={};
	int mix=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mix=max(mix,a[i]); 
	}
	int as[500001]={};
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			char c=a[i]+'0';
			if(s.find(c)) s="";
			s+=c;
		}
		for(int k=0;k<s.size();k++){
			as[s[k]-'0']++;
		}
	}
	for(int i=1;i<=mix;i++) cout<<as[i]<<" "; 
	return 0;
}
