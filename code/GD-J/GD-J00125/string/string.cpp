#include<bits/stdc++.h> 
using namespace std;
long long int n;
long long int a[2000070];
string s;
string b;
long long int len;
 long long int mid;
long long int ans;
long long int l;
long long int r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s;
		for(int i=0;i<a[i];i++){
			b+=s;
			len++;}}		
	if((len%2)!=0){
		mid=(len-1)/2;
		l=mid;
		r=mid;	 
		for(long long int i=1;i<=mid;i++){
			l--;
			r++;
			if (b[l]!=b[r]){
				ans++;		
			}		
		}
	}
///		
	else{
		mid=len/2;
		l=mid-1;
		r=mid;
	
			for(long long int i=0;i<mid;i++){
			l--;
			r++;
			if (b[l]!=b[r]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
