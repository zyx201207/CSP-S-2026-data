#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k=0,r=0;
int a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		r+=a[i];
	}
	r=r/2;
	int l=0,t=0,s=n,sum=0;
	for(int i=1;i<=n;i++){
		l+=a[i];
		if(l>r){
			l=r;
		}
		int ans=0;
		if(t!=0){
			sum+=t;
			if(b[s+1]==b[i]){
				ans+=t;
			}
			if(sum>l){
				t=sum-l;
				sum=l;
				if(b[s+1]==b[i]){
					ans-=t;
				}
				k+=a[i]-ans;
				continue;
			}
		}
		for(int j=s;j>=1;j--){
			sum+=a[j];
			if(b[j]==b[i]){
				ans+=a[j];
			}
			if(sum>l){
				t=sum-l;
				sum=l;
				if(b[j]==b[i]){
					ans-=t;
				}
				j=1;
			}
		}
		k+=a[i]-ans;
		if(l==r){
			break;
		}
	}
	cout<<k;
	return 0;
} 
