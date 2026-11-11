#include<bits/stdc++.h>
using namespace std;
int n,s,ans;
long long m,a[500005],x;
bool b=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[2]-a[1]) b=false;
	}
	if(b){
		int t;
		if(a[2]==a[1]){
			cout<<n;
			return 0;
		}
		else if(a[2]>a[1]) t=a[2]-a[1];
		else t=a[1]-a[2];
		int c=1;
		while(c<n){
			x+=c*t;
			if(c>=n-1&&x<=m){
				cout<<n;
				return 0;
			}
			if(x>m){
				cout<<c;
				return 0;
			}
			c++;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		int j=i+1;
		s=1;
		x=0;
		while(true){
			if(j>n){
				ans=max(ans,s);
				break;
			}
			x+=(a[j]-a[j-1])*(j-i);
			if(x>m){
				ans=max(ans,s);
				break;
			}
			s++;
			j++;
		}
		if(j>n) break;
	}
	cout<<ans;
	return 0;
}
