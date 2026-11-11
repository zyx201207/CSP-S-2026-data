#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[200050],t;
char s[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> s[i];
	}
	int l=1,r=n;
	while(l<r	){
		if(a[l]>a[r]){
			if(s[l]!=s[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(s[l]!=s[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else{
			if(s[l]!=s[r]){
				ans+=min(a[l],a[r]);
			}
			r--;
			l++;
		}
	}
	cout << ans;
	return 0;
}