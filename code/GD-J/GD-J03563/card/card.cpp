#include<bits/stdc++.h>
using namespace std;
long long q[10000001];
long long e[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		s+=char(a+48);
	}
	string w=s;
	for(long long i=0;i<n;i++){
		s="";
		for(long long j=i;j<w.size();j++){
			long long p=0;
			while(w[j]!=s[p]&&p<s.size()){
				p++;
			}
			if(p==s.size()-1){
				s+=s[j];
				s.erase(j,j+1);
			}
			else{
			s.erase(p,s.size());
			s+=w[j];
		}
		}
		for(long long j=0;j<s.size();j++){
			if(e[int(s[j])-48]==1){
				continue;
			}
			q[int(s[j])-48]++;
			e[int(s[j])-48]++;
		}
		for(long long j=1;j<=m;j++){
			e[j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<q[i]<<" ";
	}
	return 0;
}
