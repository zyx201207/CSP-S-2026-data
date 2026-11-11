#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char b[N]; 
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int l=1,r=n;l<r;){
		if(b[l]!=b[r])ans+=min(a[l],a[r]);
		if(a[l]==a[r]) l++,r--;
		else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else{
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}

