#include<bits/stdc++.h>
using namespace std;
int c[300001],d[10001],e[300001],p=0;
string s,sa,sb;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
		s+=(c[i]+'0');
		sa+=(c[i]+'0');
		d[c[i]]++;
		if(d[c[i]]>1){
			d[c[i]]=0;
			s="";
			for(int j=0;j<s.size();j++){
				s+=c[j]+'0';
				if(s[j]==c[i]+'0'){
					break;
				}
				
			}
		}
	}

	
	sb=sa;
	for(int i=1;i<n;i++){
		sa=sb;
		d[sa[i]-'0']++;
		if(d[c[i]]>1){
			d[c[i]]=0;
			sa="";
			for(int j=0;j<s.size();j++){
				s+=c[j]+'0';
				if(s[j]==c[i]+'0'){
					break;
				}
				
			}
		}
		for(int j=0;j<s.size();j++){
			for(int z=1;z<=m;z++){
				if(s[j]-'0'==z){
					e[j]++;
				}
			}
		}
	}
	if(n==1){
		for(int i=0;i<s.size();i++){
			for(int j=1;j<=m;j++){
				if(s[i]-'0'==j){
					e[j]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<e[i]<<' ';
	}
	return 0;
}

