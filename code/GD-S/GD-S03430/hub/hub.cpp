#include<bits/stdc++.h>
using namespace std;

int  main(){
	freopen("hub.in","r",stdin)
	freopen("hub.out","w",stdout)
		cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]!=a[i+1]){
			aa=a[i+1]-a[i];
			m=m-(aa*i);
			for(int j=0;j<i;j++){
				a[j]=a[i];
			}
		}
		if(m<=0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			s++;
		}
	}
	cout<<s+1;
} 
