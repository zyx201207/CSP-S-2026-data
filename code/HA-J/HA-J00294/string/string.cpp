#include<bits/stdc++.h>
using namespace std; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100000],ans=0;
    char c[100000];
    cin>>n;
    for(int i=0;i<n;++i){
    	cin>>a[i];
    	cin>>c[i];	
		
}for(int i=0;i<n;++i){
	if(a[i-1]<a[i]){
		ans=a[i]-a[i-1];
	}
	if(a[i-1]==a[i]){
		cout<<1;
	}
	else{
		ans=a[i];
	}
}
cout<<ans;
	return 0;
} 
