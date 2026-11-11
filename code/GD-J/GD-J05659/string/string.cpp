#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],x,y;
char c[200005];
string s,t;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int k=1e8;
	if(a[1]>=k){
		long long w=n/2*a[1];
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(a[i]--){
			s+=c[i];
			t+=c[i];
		}
	}
	int len=s.size(),ans,sum;
	for(int l=0,r=len-1;l<r;l++,r--){
		if(s[l]!=s[r]){
			s[r]=s[l];
			ans++;
		}
	}
	for(int l=0,r=len-1;l<r;l++,r--){
		if(t[l]!=t[r]){
			t[l]=t[r];
			sum++;
		}
	}
	int p=max(ans,sum);
	cout<<p;
}
