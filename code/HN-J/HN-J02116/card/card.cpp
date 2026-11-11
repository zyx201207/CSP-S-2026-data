#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,s[1000000000]={0},f[1000000000]={0};
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n){
		cin>>a;
		if(s[a]==0){
			s[a]=1;
		}else{
			s[1000000000]={0};
			s[a]=1;
		}
	}
	return 0;
} 
