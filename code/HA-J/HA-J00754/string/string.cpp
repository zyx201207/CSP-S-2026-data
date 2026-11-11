#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]&&c[l]==c[r]){
			l++,r--;
			continue;
		}
		if(a[l]==a[r]){
			ans+=a[l];
			l++,r--;
			continue;
		}
		if(a[l]<a[r]){
			int num=a[r];
			while(num!=0){
				if(a[l]<=num){
					if(c[l]!=c[r]) ans+=a[l];
					num-=a[l];
					l++;
				}else{
					if(c[l]!=c[r]) ans+=num;
					a[l]-=num;
					num=0;
				}
			}
			r--;
		}
		else{
			int num=a[l];
			while(num!=0){
				if(a[r]<=num){
					if(c[l]!=c[r]) ans+=a[r];
					num-=a[r];
					r--;
				}else{
					if(c[l]!=c[r]) ans+=num;
					a[r]-=num;
					num=0;
				}
			}
			l++;
		}
	}
	cout<<ans;
	return 0;
}
