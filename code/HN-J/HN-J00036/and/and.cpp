#include<bits/stdc++.h>
using namespace std;
int n,m,s,b,f;
int a[101010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			s=max(a[i],a[i+1]);
		}
		cout<<s;
	} 
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				f=a[i]&a[j];
				if(s<=f){
					s=f;
				}
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				for(int g=2;g<=n;g++){
				f=max(max(a[i]&a[j],a[i]&a[g]),a[j]&a[g]);
				if(s<=f){
					s=f;
				}
				
				}
			}
		}
	}
	if(m==n){
	   for(int i=1;i<=n+1;i++){
	   	  s+=a[i]&a[+1]; 
	   } 
	} 
	cout<<s;
	return 0;
}  
