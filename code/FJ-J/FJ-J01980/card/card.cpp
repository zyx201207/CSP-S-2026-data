#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050],t[300050],ta[300050],tw[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		fill(t+1,t+m+1,0);
		for(int j=i;j<n;j++){
			t[a[j]]++;
			if(t[a[j]]==1){
				tw[a[j]]=j;
			}
			if(t[a[j]]==2){
				for(int z=tw[a[j]];z<=j;z++){
			t[a[z]]=0;
	}
				t[a[j]]=1;
				tw[a[j]]=j;
			}
	}
	for(int j=1;j<=m;j++){
		ta[j]+=t[j];
	}
	}
	for(int j=1;j<=m;j++){
		cout<<ta[j]<<" ";
	}
return 0;} 
