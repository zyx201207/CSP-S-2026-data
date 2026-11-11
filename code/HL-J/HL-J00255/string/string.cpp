#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long cnt=0;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
		if(c[i]!=c[1]) f=0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	long long mid;
	if(cnt%2==0) mid=cnt/2;
	else mid=cnt/2+1;
	long long sum=0;
	int p;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=mid){
			p=i;
			break;
		}
	}
	long long ans=0;
	int l=1;
	for(int i=n;i>=p;i--){
		if(i!=p){
			int x=min(a[i],a[n+l-i]);
			if(c[i]!=c[n+l-i]) ans+=x;
			a[i]-=x;
			a[n+l-i]-=x;
			if(a[i]>a[n+l-i]) l++;
			if(a[i]<a[n+l-i]) l--;
		}
	}
	if(a[p]!=0){
		if(l<1){
			if(c[p]!=c[p-1]) ans+=min(a[p],a[p-1]);
		}
	}
	cout<<ans;
	return 0;
}
