#include<bits/stdc++.h>
using namespace std;

long long ans,bns,n,num;
char s[100000001];
char cc;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		cin>>cc;
		
		for(int j=1;j<=num;j++){
		bns++;
		s[bns]=cc;
		}
	}

		for(int i=1;i<=bns/2;i++){
			if(s[i]!=s[bns+1-i]){
				ans++;
			}
		}
	
	cout<<ans;
	
	
	
	
	return 0;
}
