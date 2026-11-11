#include<bits/stdc++.h>
using namespace std;
struct node{
	long long len;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,ans=0;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(long long i=1;i<=n;i++) cin>>a[i].len>>a[i].c;
	long long l=1,r=n;
	while(l<=r){
		if(a[l].c!=a[r].c){
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				ans+=a[l].len;
				l++;
			}else if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				ans+=a[r].len;
				r--;
			}else{
				ans+=a[l].len;
				l++;
				r--;
			}
		}else{
			if(a[l].len<a[r].len){
				a[r].len-=a[l].len;
				l++;
			}else if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
}
