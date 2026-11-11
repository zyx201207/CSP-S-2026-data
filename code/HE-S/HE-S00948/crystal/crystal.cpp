#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;long long m;cin>>m;int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}int z=0;int s[n];int v=0;memset(s,0,sizeof(s));
	for(int i=0;i<n;i++){
		z=0;
		for(int j=0;j<i;j++){
			z+=a[i]-a[j];
			if(z==m){
				s[v]=i+1;v++;
			} 
		}
	}
	sort(s,s+v);cout<<s[v-1];
	return 0;
} 
