#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],ans=0;
char c,s[200010];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	while(l<r){
		if(a[l]>a[r]){
			if(s[l]==s[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		if(a[r]>a[l]){
			if(s[l]==s[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
		if(a[l]==a[r]){
			if(s[l]==s[r]){
				l++;
				r--;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
