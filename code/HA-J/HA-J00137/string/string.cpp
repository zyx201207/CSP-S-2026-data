#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n;
int a[N];
char c[N];
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=1LL*a[l];
			}
			l++;
			r--;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=1LL*a[r];
			}
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r]){
				ans+=1LL*a[l];
			}
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 
