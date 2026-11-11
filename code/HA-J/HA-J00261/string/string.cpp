#include <bits/stdc++.h>
using namespace std;
string ALL;
long long L,TLL;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);	
	cin>>L;
	for(long long i=0;i<L;i++){
		string a;
		long long b;
		cin>>b>>a;
		for(int i=0;i<b;i++){
			ALL+=a;
		}
	}
	long long AALS=ALL.size()/2;
	long long ALLS=ALL.size();
	for(long long i=1;i<=AALS;i++){
		if(ALL[i]!=ALL[ALLS-1]){
			TLL++;
		}
	}
	cout<<TLL;
	return 0;
}
