#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,k=0,ke=0;
	cin>>n;
	long long a[n];
	char s[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		k=k+a[i];
	}
	for(int i=0;i<n;i++){
		if(k%2==0){
			if(s[i]!=s[n-i-1]){
				ke=ke+a[i];
			}
		}else{
			a[n/2]=a[n/2]-1;
			if(s[i]!=s[n-i-1]){
				ke=ke+a[i];
			}
		}
	}
	if(ke==0){
		cout<<ke<<endl;
	}else{
		cout<<ke-1<<endl;
	}
	return 0;
}
