#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long n,a[200005],s[200005],l=0,r=n+1,sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	l=0,r=n+1;
	while(l+1<r){
//		cout<<l<<" "<<r<<" "<<sum<<"\n";
		while((l==0||s[l]<=s[n]-s[r-1])&&l+1<r){
			if(r!=n+1)sum+=(c[l+1]!=c[r])*min(a[l+1],(s[n]-s[r-1])-s[l]);
			l++;
//			cout<<l<<" "<<r<<" "<<sum<<"\n";
		}
		while((r==n+1||s[l]>=s[n]-s[r-1])&&l+1<r){
			if(l!=0)sum+=(c[l]!=c[r-1])*min(a[r-1],s[l]-(s[n]-s[r-1]));
			r--;
			//cout<<l<<" "<<r<<" "<<sum<<"\n";
		}
	}
	cout<<sum;
	return 0;
}
