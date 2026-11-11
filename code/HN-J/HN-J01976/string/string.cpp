#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0,L=1,tot=0;
struct jgt{
	int l,r,siz;
	char c;
};
vector<jgt> v;
vector<int> v1;
map<int,char> mp;
int check(int x){
	int l=0,r=v1.size(),ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(v1[mid]>=x){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return v1[ans];
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		jgt dq;
		dq.c=c;
		dq.l=L;
		dq.r=L+a-1;
		dq.siz=a;
		L=dq.r+1;
		tot+=a;
		v.push_back(dq);
		mp[dq.l]=c;
		mp[dq.r]=c;
		v1.push_back(dq.r);
	}
	int len=v.size();
	for(int i=0;i<len;i++){
		jgt dq=v[i];
		int l=dq.l;
		int r=dq.r;
		if(dq.l>tot/2) break;
		int nr=tot-l+1;
		int nl=tot-r+1;
		if(nl<tot/2) nl=tot/2+1; 
		while(nl<=nr){
			int nnl=check(nl);
			int nl2=nnl;
			if(nl2>nr) nl2=nr;
			if(mp[nnl]!=dq.c) ans+=nl2-nl+1;
			nl=nl2+1;
		}
	}
	cout<<ans;
	return 0;
}
