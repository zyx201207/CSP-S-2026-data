#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n;
int a[maxn];
char op[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>op[i];
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	int l=1,r=n;
	int idl=0,idr=sum;
	int ans=0;
	while(l<=r){
		if(op[l]==op[r]){
			int tmp=min(a[l],a[r]);
			idl+=tmp;
			idr+=tmp;
			bool ok1=0,ok2=0;
			if(tmp==a[l]) ok1=1;
			else ok2=1;
			a[l]-=tmp;
			a[r]-=tmp;
			if(ok1) l++;
			if(ok2) r--;
		}
        else{
        	int tmp=min(a[l],a[r]);
        	ans+=tmp;
        	idl+=tmp;
			idr+=tmp;
			bool ok1=0,ok2=0;
			if(tmp==a[l]) ok1=1;
			else ok2=1;
			a[l]-=tmp;
			a[r]-=tmp;
			if(ok1) l++;
			if(ok2) r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
回文串：
a[1]=a[n]
a[2]=a[n-1]

定义指针 l,r
对于a[l]和a[r]
如果说op[l]==op[r] idx+==
2a
2b
*/ 
