#include<bits/stdc++.h>
using namespace std;
int a[200005];
int s[200005]={1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,1048575,};
int mx;
int mxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   	int n,m;
   	cin>>n>>m;
   	for(int i=0;i<n;i++){
   		cin>>a[i];
   		mxx=max(mxx,a[i]);
	} 
   	if(m==1) cout<<mxx;
   	else{
   		for(int i=0;i<n-m;i++){
   			for(int j=0;j<=m;j++){
   				s[i]=s[i]&a[i+j];
   				
		   }
		   mx=max(s[i],mx);	
		}
	}
	cout<<mx;
}

