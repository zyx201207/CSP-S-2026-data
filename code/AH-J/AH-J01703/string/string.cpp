#include<bits/stdc++.h>
using namespace std;
int a[200005],l,r,ls,rs,n;
char s[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l=1;
	r=n;
	ls=a[l];
	rs=a[r];
	while(l<r){
		if(ls<rs){
			if(s[l]!=s[r]){
				ans+=ls;
				rs-=ls;
				l++;
				ls=a[l];
				
			}
			else{
				rs-=ls;
				l++;
				ls=a[l];
				
			}
		}
		else if(ls>rs){
			if(s[l]!=s[r]){
				ans+=rs;
				ls-=rs;
				r--;
				rs=a[r];
				
			}
			else{
				ls-=rs;
				r--;
				rs=a[r];
				
			}
		}
		else{
			if(s[l]!=s[r]){
				ans+=rs;
				r--;
				rs=a[r];
				l++;
				ls=a[l];
			}
			else{
				r--;
				rs=a[r];
				l++;
				ls=a[l];
			}
		}
	}
	cout<<ans;
	return 0;
} 
