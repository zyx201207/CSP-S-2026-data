#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n=0,m=0;
	cin>>n>>m; 
	string s="";
	int p[n]={},mm[m]={};
	for(int i=0;i<n;i++) cin>>p[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<s.size();k++){
				if(int(s[k])-48==p[j]){
					string l="";
					for(int x=0;x<k;x++) l+=s[x];
					s=l;
				}
			}
			s+=char(p[j]+48);
		}
		for(int j=0;j<s.size();j++) mm[int(s[j])-49]++;
		s="";
	}
	for(int i=0;i<m;i++) cout<<mm[i]<<' ';
	return 0; 
}
