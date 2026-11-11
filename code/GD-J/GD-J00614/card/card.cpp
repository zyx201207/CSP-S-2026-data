#include<bits/stdc++.h>
using namespace std;
long long n,m,e[5000000+5],s[1000000+250],book[1000000+250];
long long ans[1000000+250],sum[1000000+250];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) ans[i]=i;
	for(int i=1;i<=n;i++){
		cin>>e[i];
		s[i]=1;
		if(book[e[i]]!=0){
			s[book[e[i]]]-=ans[book[e[i]]];
			s[i]+=ans[book[e[i]]];
		}
		book[e[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1]+s[i];
		if(ans[i]>0) book[e[i]]=ans[i]; 
	}
	for(int i=1;i<=m;i++) cout<<book[i]<<' ';	
	return 0;
}

