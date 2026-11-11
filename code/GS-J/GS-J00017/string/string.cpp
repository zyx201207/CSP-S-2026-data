#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a;
	string c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	long long si=s.size();
	long long i=0,j=si-1,count=0;
	for(;i<si/2;j--,i++){
		if(i==j){
			break;
		}
		if(s[i]!=s[j]){
			count++;
		}
	}
	cout<<count;
	return 0;
}
