#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int l=1,r=n;l<r;){
		if(c[l]==c[r]){
			if(a[l]<a[r]) {a[r]-=a[l],l++;}
			else if(a[l]==a[r]) {l++,r--;}
			else {a[l]-=a[r],r--;}
		}
		else{
			if(a[l]<a[r]) {a[r]-=a[l],ans+=a[l],l++;}
			else if(a[l]==a[r]) {ans+=a[l],l++,r--;}
			else {a[l]-=a[r],ans+=a[r],r--;}
		}
	}
	cout<<ans;
	return 0;
}
