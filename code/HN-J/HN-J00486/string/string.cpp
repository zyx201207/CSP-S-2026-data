#include<bits/stdc++.h>
using namespace std;
string c;
int a[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,l,r;
	long long ans=0;
	bool ok=1;
	cin>>n;
	l=0;
	r=n-1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		while(l<=r){
			if(c[l]!=c[r]){
				ok=0;
				break;
			}
			l++;
			r--;
		}
		if(ok){
			cout<<0;
			return 0;
		}else if(!ok){
			ans=min(a[0],a[1]);
			cout<<ans;
			return 0;
		}
	}
	if(n%2!=0){
		while(l<=r){
			if(c[l]!=c[r]){
				ans+=max(a[l],a[r]);
			}
			l++;
			r--;
		}
		if(ans==0){
			l=0;
			r=n-1;
			while(l<=r){
				if(a[l]!=a[r]){
					ans+=min(a[l],a[r]);
				}
				l++;
				r--;
			}
			ans++;
		}
	}else{
		while(l<=r){
			if(c[l]!=c[r]){
				ans+=min(a[l],a[r]);
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
