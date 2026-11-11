#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],h=0,g;
string s,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	g=n-1;
	int i=0;
	while(g-i>1){
		if(s[i]==s[g]){
			if(a[i]>a[g]){
				a[i]=a[i]-a[g];
				g--;
			}else if(a[i]<a[g]){
				a[g]=a[g]-a[i];
				i++;				 
			}else{
				i++;
				g--;
			}
		}else{
			if(a[i]>a[g]){
				a[i]=a[i]-a[g];
				g--;
				h+=a[g];
			}else if(a[i]<a[g]){
				a[g]=a[g]-a[i];
				i++;
				h+=a[i];			 
			}else{
				i++;
				g--;
				h+=a[g];
			}
		}
	}
	if(n%2==0){
		if(s[i]==s[g]){
			if(a[i]>a[g]){
				a[i]=a[i]-a[g];
				g--;
			}else if(a[i]<a[g]){
				a[g]=a[g]-a[i];
				i++;				 
			}else{
				i++;
				g--;
			}
		}else{
			if(a[i]>a[g]){
				a[i]=a[i]-a[g];
				g--;
				h+=a[g];
			}else if(a[i]<a[g]){
				a[g]=a[g]-a[i];
				i++;
				h+=a[i];		 
			}else{
				i++;
				g--;
				h+=a[g];
			}
		}
	}
	cout<<h;
	return 0;
} 
