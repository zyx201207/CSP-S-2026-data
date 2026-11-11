#include<bits/stdc++.h>
using namespace std;

long long n,l,r,len,ans;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	
	long long i=1,j=n,k=0;
	l=a[i],r=a[j];
	while(i!=j){
		if(c[i]!=c[j]){
			int x=min(l-k,r-k);
			ans+=x;
			if(l-k<r-k){
				i++;
				l+=a[i];
				l=min(l,len/2);
			} 
			else{
				j--;
				r+=a[j];
				r=min(r,len/2);
			}
			k+=x;
		}
		else{
			int x=min(l-k,r-k);
			if(l-k<r-k){
				i++;
				l+=a[i];
				l=min(l,len/2);
			} 
			else{
				j--;
				r+=a[j];
				r=min(r,len/2);
			}
			k+=x;
		}
	}
	cout<<ans;
	return 0; 
}
