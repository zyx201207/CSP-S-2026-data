#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i].n>>a[i].c;
	long long l=1,r=n,ans=0;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		if(a[l].c==a[r].c){
			long long x=min(a[l].n,a[r].n);
			a[l].n-=x,a[r].n-=x;
			if(a[l].n==0)	l++;
			if(a[r].n==0)	r--;
		}else{
			long long x=min(a[l].n,a[r].n);
			ans+=x;
			a[l].n-=x,a[r].n-=x;
			if(a[l].n==0)	l++;
			if(a[r].n==0)	r--;
		}
	}
	cout<<ans;
	return 0;
}
