#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>	
using namespace std;
int n,a;
string s=""; 
long long m=0,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int aa;
	char cc;
	for(int i=1;i<=n;i++){
		cin>>aa>>cc;
		for(int j=1;j<=aa;j++){
			s+=cc;
		}
	}
	for(int i=0;i<(s.size()/2);i++){
		if(s[s.size()-1-i]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}	
