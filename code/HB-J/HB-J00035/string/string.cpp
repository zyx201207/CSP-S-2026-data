#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0,r=0,cnt,h;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(long long i=0,j=0;i+j<n;){
		if(l+a[i]>r+a[n-1-j]){
			if(c[i]!=c[n-1-j]){
				cnt=cnt+(r+a[n-1-j]-max(l,r));
			}r+=a[n-1-j];
			j++;
		}else if(l+a[i]<r+a[n-1-j]){
			if(c[i]!=c[n-1-j]){
				cnt=cnt+(l+a[i]-max(l,r));
			}l+=a[i];
			i++;
		}else if(l+a[i]==r+a[n-1-j]){
			if(c[i]!=c[n-1-j]){
				cnt=cnt+(l+a[i]-max(l,r));
			}l+=a[i];
			r+=a[n-1-j];
			i++;
			j++;
		}
	}cout<<cnt;
	return 0;
}
