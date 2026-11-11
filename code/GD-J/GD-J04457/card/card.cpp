#include<bits/stdc++.h>
using namespace std;
int n,m,s[1000001],s1[1000001];
int main(){
	freopen("card.in"."r",stdin);
	freopen("card.out"."w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[j]==i){
				s1[i]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s1[i]<<" ";
	}
	return 0;
}
