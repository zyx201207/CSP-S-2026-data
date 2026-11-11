#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum;
long long x[212345];
char y[30];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		for(int j=1;j<=x[i];j++){
			s+=y[i];
		}
		sum+=x[i];
	}
	for(int i=sum/2+1;i>=1;i--){
		if(s[i]==s[sum-i+1]) continue;
		else cnt++;
	} 
	cout<<cnt;
	return 0;
} 

