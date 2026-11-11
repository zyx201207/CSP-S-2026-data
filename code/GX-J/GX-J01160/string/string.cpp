#include<bits/stdc++.h>
using namespace std;
int a[200005];//aabba
long long ans;
char b[200005];
int meow(int l,int r){
	if(l>=r){
		cout<<ans;
		return 0;
	}
	if(b[l]!=b[r]){
		ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
			return meow(l,r);
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				return meow(l,r);
			}else{
				if(a[l]==a[r]){
					l++;r--;
					return meow(l,r);
				}
			}
		}
		return meow(l,r);
	}else{
		if(a[l]==a[r]){
			l++,r--;
			return meow(l,r);
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				return meow(l,r);
			}else{
				if(a[l]<a[r]){
					a[r]-=a[l];
					l++;
					return meow(l,r);
				}
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	meow(l,r);
	return 0;
}

