#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long s,ans,b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		b[i]=s;
	}long long m;
	for(int i=n;i>=1;i--){
		if(s/2+1<=b[i]){
			m=i;
		}
	}if(s%2!=0)a[m]--;
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}else if(a[r]<a[l]){
			a[l]-=a[r];
			r--;
		}else r--,l++;
	}cout<<ans;
	return 0;
} 
