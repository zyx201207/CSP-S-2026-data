#include<bits/stdc++.h>
using namespace std;
int n,sas=0,k=0;
int a[20005],b[20005];
string s[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
		}
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
		cin>>s[i];
		}
	if(n==2){
		if(s[0]==s[1]){
			cout<<0;
			return 0;
			}
		if(a[0]==a[1]){
			cout<<a[0];
			return 0;
			}
		if(a[0]>a[1]){
			cout<<a[1];
			return 0;
			}
		if(a[0]<a[1]){
			cout<<a[0];
			return 0;
			}		
		}
		for(int i=0;i<n;i++){
			if(a[i]!=1){
				sas=1;
				}
		}
		if(sas==0){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(a[i]==b[j]){
						k++;
						break;
						}
			}
			}
		}
		if(k%2==0){
			cout<<n-((k+1)/2);
			return 0;
			}
			cout<<n-(k/2);
	return 0;
}
