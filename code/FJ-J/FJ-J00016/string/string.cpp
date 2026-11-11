#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
ll a[N];
char c[N];
int n;
ll ans,l,r; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(l<=r){
		if(a[l]<a[r]){
			a[r]-=a[l];
			if(c[l]!=c[r])ans+=a[l];
			l++;
		}else if(a[r]<a[l]){
			a[l]-=a[r];
			if(c[l]!=c[r])ans+=a[r];
			r--;	
		}else{
			if(c[l]!=c[r])ans+=a[l];
			l++,r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
