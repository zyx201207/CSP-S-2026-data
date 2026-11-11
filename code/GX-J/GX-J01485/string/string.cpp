#include <bits/stdc++.h>
using namespace std;
const long long N =1e9+10;
long long n,b,c=0,sum=0;
string s;
char a[N];
int main(){
	freopen("string4.in","r",stdin);
	freopen("string4.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b>>a[i];
		for(int j=0;j<b;j++){
			s=s+a[i];
		}
	}
	if(s.size()%2==0){
		c=s.size();
		for(int i=0;i<c/2;i++){
			if(s[i]==s[n-i]) sum+=0;
			else sum++;
		}
	}
	else{
		c=s.size()-1;
		for(int i=0;i<c/2;i++){
			if(s[i]==s[n-i]) sum+=0;
			else sum++;
		}
	}
	
	cout<<sum;


	return 0;
}
