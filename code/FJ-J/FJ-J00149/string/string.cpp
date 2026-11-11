#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[200005];
long long n;
char c[200005];
long long tmp=1;
long long mid=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		long long t1;
		char t2;
		cin>>t1>>t2;
		if(t2==c[tmp-1]) a[tmp-1]+=t1;
		else a[tmp]=t1,c[tmp++]=t2;
		mid+=t1;
	}
	mid=(mid+1)/2;
	tmp--;
	long long l=1,r=tmp;
	while(l<r){
		long long h=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=h;
		a[l]-=h;
		a[r]-=h;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
