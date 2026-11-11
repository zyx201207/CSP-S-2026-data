#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+30;
int n,a[N];
char s[N];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		int t=min(a[l],a[r]);
		if(s[l]==s[r]){
			a[l]-=t;
			a[r]-=t;			
		}else{
			a[l]-=t;
			a[r]-=t;
			ans+=t;
		}
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
