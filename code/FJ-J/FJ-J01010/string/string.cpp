#include<bits/stdc++.h>
using namespace std;
const long long N=1E9+10;
char a1[N];
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("atring.out","w",stdout);
	int n;
	bool sp=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long vis;
		cin>>vis>>c[i];
		a[i]=vis+a[i-1];
		if(i>1&&sp==1&&c[i]!=c[i-1])
			sp=0;
	}
	if(sp==1){
		cout<<0;
		return 0;
	}
	int x=a[n]/2;
	int mth=1;
	
	for(int i=1;i<=n;i++){
		for(int l=mth;l<=a[i];l++){
			a1[l]=c[i];
		}
		mth+=a[i]+1;
	}
	long long ans=0;
	for(int i=1;i<=x;i++){
		if(a1[i]!=a[n-i+1])
			ans++;
	}
	cout<<ans;
	
	return 0;
}
