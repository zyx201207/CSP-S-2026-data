#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int n,ans;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	int i=1;
	int j=n;
	while(i){
		while(j>=i){
			if(j==i){
				cout<<ans; 
				return 0;	
			}
			if(s[i]==s[j]){
				if(a[i]>a[j]){
					a[i]=a[i]-a[j];
					j--;
					break;
				}
				if(a[i]<a[j]){
					a[j]=a[j]-a[i];
					i++;
					break;
				}
				if(a[i]==a[j]){
					j--;
					i++;
					break;
				}
			}
			if(s[i]!=s[j]){
				if(a[i]>a[j]){
					a[i]=a[i]-a[j];
					ans=ans+a[j];
					j--;
					break;
				}
				if(a[i]<a[j]){
					a[j]=a[j]-a[i];
					ans=ans+a[i]; 
					i++;
					break;
				}
				if(a[i]==a[j]){
					ans=ans+a[i]; 
					j--;
					i++;
					break;
				}
				break; 
			}
		}
	} 
	cout<<ans; 
	return 0;
}
