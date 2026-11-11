#include<bits/stdc++.h>
using namespace std;

struct node{
	long long lo;
	char c;
}a[200100];

long long n,ans,l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i].lo>>a[i].c;
	l=1;
	r=n;
	while(l<=r){
		if(a[l].lo>a[r].lo){
			if(a[l].c!=a[r].c){
				ans+=a[r].lo;
			}
			a[l].lo-=a[r].lo;
				r--;
		}else if(a[l].lo<a[r].lo){
			if(a[l].c!=a[r].c){
				ans+=a[l].lo;
			}
			a[r].lo-=a[l].lo;
			l++;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[l].lo;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
