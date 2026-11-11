#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s,min=1000,l,k;
	for(int i=1;i<=m;i++){
		if(a[i]==a[i+1]){
			s+=2;
			k=a[i+1];
		}
		if(a[i]<min){
			a[i]==min;
			l=k-a[i];
			a[i]++;
		}
	}
	while(m==0){
		for(int i=1;i<=n;i++){
			a[i]+=1;
			m--;
		}
		s+=1;
	}
	cout<<s;
}
