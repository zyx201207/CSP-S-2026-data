#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0,ans=0;
long long x;
int a[200005];
char s[200005];
long long v[200005];
int find(long long x){
	long long l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(v[mid]<x){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	return r;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		cnt+=a[i];
		v[i]=cnt;
	}
	x=cnt/2;
    while(x>0){
	    int f1=find(x),f2=find(cnt-x+1);
	    int k=min(x-v[f1-1],v[f2]+x-cnt);
    	x-=k;
    	if(s[f1]!=s[f2]) ans+=k;
	}
	cout<<ans;
	return 0;
}
