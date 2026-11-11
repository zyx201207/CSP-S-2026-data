#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=1e5+5; 
long long h[N],a[N];

long long find_minnest(long long t[]){
	long long mn=2e9,xb;
	for(int k=1;k<=n;k++){
		if(t[k]<mn){
			mn=t[k];
			xb=k;
		}
	}
	return xb;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		h[a[i]]++;
	}
	
	if(m==0){
		for(int i=1;i<=n;i++){
			h[a[i]]++;
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]+1==a[i+1]){
				h[a[i+1]]++;
				h[a[i]]--;
			}
		}
	}
	else if(m>1){
		long long zxxb;
		for(int i=1;i<=m;i++){
			zxxb=find_minnest(a);
			h[a[zxxb]]--;
			h[++a[zxxb]]++;
		}
	}
	long long mxm=-2e9;
	for(int i=1;i<=n;i++){
		mxm=max(mxm,h[i]);
	}
	cout<<mxm;
	return 0;
}
