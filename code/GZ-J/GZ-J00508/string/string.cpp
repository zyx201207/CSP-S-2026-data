//GZ-J00508 敖翔 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long cs;
long long n;
long long gs[200005];
char a[200005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>gs[i]>>a[i];
	}
	for(long long i=0;i<n;i++){
		if(a[i]==a[n-i-1]) continue;
		if((i==n-i-1&&n%2!=0)||(i==n-i)) break;
		cs++;
		if(gs[i]==gs[n-i-1]) {
			cnt+=gs[i];
			continue;
		} 
		if(gs[i]>gs[n-i-1]) {
			cnt+=(gs[i]-gs[n-i-1]);
			continue;
		}
		cnt+=(gs[n-i-1]-gs[i]);
	}
	cout<<cnt<<'\n';
	return 0;
} 
