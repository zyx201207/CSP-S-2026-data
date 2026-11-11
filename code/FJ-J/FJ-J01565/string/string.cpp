#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
char e[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>e[i];
	}int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
			if(e[l]!=e[r]){
				ans+=a[l];
			}l++;
			r--;
		}else if(a[l]>a[r]){
			if(e[l]!=e[r]){
				ans+=a[r];
			}a[l]-=a[r];
			r--;
		}else{
			if(e[l]!=e[r]){
				ans+=a[l];
			}a[r]-=a[l];
			l++;
		}
	}cout<<ans;
	return 0;
}
