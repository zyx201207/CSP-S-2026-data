#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	stack <long long> b;
	cin>>n>>m;
	long long a[500050]={};
	long long s1[300050]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}
	for(long long u=1;u<=n;u++){
		long long s[300050]={};
		for(long long i=u;i<=n;i++){
			b.push(a[i]);
			if(s[a[i]]!=0){
				b.pop(); 
				while(b.top()!=a[i]){
					s[b.top()]=0;
					b.pop();
				}
			}
			s[a[i]]=1;	
		}
		for(long long i=1;i<=m;i++){
			if(s[i]==1) s1[i]+=1;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<s1[i]<<" ";
	}
}
