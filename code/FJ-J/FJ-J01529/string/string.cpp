#include<bits/stdc++.h> 
using namespace std;
long long a[200005];
int n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=a[1],r=a[n],p=1,q=n,ans=0;
	while(p<=q){
		if(c[q]!=c[p]){
			ans+=min(l,r);
		}
		long long minn=min(l,r);
		l-=minn;
		r-=minn;
		if(l==0){
			p++;
			l=a[p];
		}
		if(r==0){
			q--;
			r=a[q];
		}
	}
	cout<<ans;
	return 0;
}
