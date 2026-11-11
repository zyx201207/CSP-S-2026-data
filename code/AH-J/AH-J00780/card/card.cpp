#include <bits/stdc++.h>
using namespace std;
long long n,m;
string s,t,r;
long long xl[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	stringstream sin;
	sin<<s;
	while(sin>>t){
		r+=t;
	}
	for(long long i=0;i<r.size();i++){
		string x;
		for(long long j=i;j<r.size();j++){
			if(x.find(r[j])!=string::nops){
				long long q=x.find(r[j]);
				long long len=x.size()-1;
				x.erase(q+1,len-q);
			}
			else{
				x+=r[j];
			}
		}
		for(long long z=0;z<x.size();z++){
			xl[int(x[z]-"0")]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<xl[i]<<" ";
	}
	return 0;
}
