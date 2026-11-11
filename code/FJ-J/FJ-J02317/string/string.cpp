#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n[200050],i,w,x=0,j,ans=0;
	string a;
	cin>>w;
	for(i=0;i<w;i++){
		cin>>n[i];
		cin>>a[i];
	}
	for(i=0;i<w;i++){
		if(a[i]==a[i+1])x++;
    }
     if(x==w-1){
     	cout<<0;
     	return 0;
	 } 
	 	for(i=0;i<=w/2;i++){
	 		if(a[i]!=a[w-i]){
	 			if(n[i]>=n[w-i])ans+=n[i];
	 			else ans+=n[w-i];
			 }
		 }
		 cout<<ans;
	return 0;
}
