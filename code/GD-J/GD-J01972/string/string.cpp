#include<bits\stdc++.h>
using namespace std;
string s;
long long n;
bool p=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		string s2;
		long long x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s2+=y;
		}
		s+=s2;
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1]){
			p==0;
		}
	}
	if(p==1){
		cout<<0;
	}else{
		cout<<sizeof(s)/2;
	}
	return 0;
} 
