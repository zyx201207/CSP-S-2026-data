#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
int a[maxn];
char c[maxn];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n,i=0,j=0;
	for(;;){
//		cout<<l<<" "<<r<<" "<<i<<" "<<j<<"\n"; 
		if(l==r){
			break;
		}
		if(l>r){
			ans-=(a[l]!=a[r]);
			if(i==0)i=a[--l]-1;
			if(j==0)j=a[++r]-1;
			break;
		}
		int tmp=min(a[l]-i,a[r]-j);
		if(c[l]!=c[r]){
			ans+=tmp;
		}
		i+=tmp,j+=tmp;
		if(i>=a[l])i%=a[l],l++;
		if(j>=a[r])j%=a[r],r--;
	}
	cout<<ans;
} 
