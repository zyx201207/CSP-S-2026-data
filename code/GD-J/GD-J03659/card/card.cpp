#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
long long to[300001];
long long la[300001];
long long ans[300001];
void df(int st){
	for(int i=1;i<=m;i++) to[i]=la[i]=0;
	for(;st<=n;st++){
		if(to[a[st]]){
			for(int i=la[a[st]];i<st;i++){
				to[a[i]]=0;
				la[a[i]]=0;
			}
		}
		to[a[st]]++;
		la[a[st]]=st;
	}
	for(int i=1;i<=m;i++){
		if(to[i]) ans[i]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			df(i);
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	else if(m>2){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		} 
		return 0;
	}
	else if(m==2){
		a[n]=n;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				ans[a[i]]++;
			}
		}
		for(int i=1;i<=2;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	else if(m==1){
		cout<<n;
		return 0;
	}
	return 0;
}
