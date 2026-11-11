#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,l=0,w=0;
	int a[n+5];
	char s[n+5];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	
	for(int i=0;i<n;i++){
		m+=a[i];
	}
	int b[100000000];
	for(int i=0;i<m;i++){
		for(int j=0;j<a[i];j++){
			b[i]=s[i];
		}
	}
	if(m%2==0){
		m=m/2;
		if(b[m]!=b[m+1]){
			l+=1;
		}
		for(int i=0;i<m;i++){
			
			if(b[m-i]!=b[m+1+i]){
				l++;
			}
		}
	}
	else{
		m=m/2;
		for(int i=0;i<m+1;i++){
			if(b[m-i]!=b[m+i]){
				l++;
			}
		}
	}

	if(w==m){
		cout<<"0";
	}
	else{
		cout<<l;
	}
	return 0;
}
