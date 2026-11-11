#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[0x3f];
char s[0x3f];
long long ans[12];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    int k=0;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
		
	}
	
	long long l=0,r=n-1;
	while(l<=n){
		if(s[l]!=s[r]&&a[l]>0&&a[r]>0){
			ans[k]++;		
		}
		a[l]--;a[r]--;
		if(a[l]<=0) l++;
		if(a[r]<=0) r--;
		if(a[k]>=99999999) k++;
	}
	cout<<k*999999999+ans[k];
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
