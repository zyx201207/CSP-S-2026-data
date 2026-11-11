#include<bits/stdc++.h>
using namespace std;
int a[210000];
char c[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	int x=n,s=1;
	while(s<x){
		if(c[s]!=c[x]){
			ans+=min(a[x],a[s]);	
		}
		if(a[s]>a[x]){
			a[s]-=a[x];
			a[x]=0;
			x--;
		}else if(a[s]==a[x]){
			x--;
			s++;
		}else{
			a[x]-=a[s];
			a[s]=0;
			s++;	
		}	
	}
	cout<<ans;
	return 0;
}
