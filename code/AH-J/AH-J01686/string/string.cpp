#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200005];
char c[200005];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	int x=a[1],y=a[n];
	while(l<=r){
		if(x<y){
			if(c[l]!=c[r]){
				ans+=x;
			}
			y=y-x;
			l++;
			x=a[l];
		}
		else if(x>y){
			if(c[l]!=c[r]){
				ans+=y;
			}
			x=x-y;
			r--;
			y=a[r];
		}
		else {
			if(c[l]!=c[r]){
				ans+=x;
			}
			l++;
			x=a[l];
			r--;
			y=a[r];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
