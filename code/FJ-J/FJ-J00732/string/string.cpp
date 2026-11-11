#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e5+10;
int n;
int idx;
int a[MAXN];
char c[MAXN];
ll ans;
int l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	r=n-1;
	while(l<=r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			l++,r--;
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}
