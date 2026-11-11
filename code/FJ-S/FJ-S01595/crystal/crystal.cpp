#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> a;
vector<int> b;
int ans=0;
void bigg(){
	for(int l=0;l<n-1;l++){
		int mx=0,mmx=0;
		for(int r=l;r<n;r++){
			if(mx+(r-l+1)*b[r]>m){
				if(mmx+1>ans)ans=mmx+1;
				l++;
				break;
			}
			else{
				mx=mx+(r-l+1)*b[r];
				mmx++;
			} 
		}
		if(mmx>ans)ans=mmx;
	}
	return ;
}
void aaa(){
	int mx=0,mmx=0;
	for(int r=0;r<n;r++){
		if(mx+r+1>m){
			if(mmx+1>ans)ans=mmx+1;
			break;
		}
		else{
			mx=mx+r+1;
			mmx++;
		}
		if(mmx>ans)ans=mmx;
	}
	return ;
}
void bbb(int bb){
	int mx=0,mmx=0;
	for(int r=0;r<n;r++){
		if(mx+(r+1)*bb>m){
			if(mmx+1>ans)ans=mmx+1;
			break;
		}
		else{
			mx=mx+(r+1)*bb;
			mmx++;
		}
		if(mmx>ans)ans=mmx;
	}
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	int BB=a[1]-a[0];bool BBB=0;
	for(int i=1;i<n;i++){
		b[i-1]=a[i]-a[i-1];
		if(BB!=b[i-1])BBB=1;
	}
	if(BBB)bigg();
	else if(BB==1)aaa(); 
	else bbb(BB);
	printf("%lld",ans);
	return 0;
}
