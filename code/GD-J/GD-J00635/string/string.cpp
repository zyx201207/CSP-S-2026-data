#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n,p=a[1]-a[n];
	bool c;//c=1代表上一个选l 
	if(a[1]>a[n]) c=0;
	else c=1;
	while(l<r){
		if(p<0){
			if(b[l]!=b[r]){
				if(c==1) ans+=a[l];
				else{
					ans-=p;
				}
			}
			l++;
			p+=a[l];
			c=1;
		}
		else if(p>0){
			if(b[l]!=b[r]){
				if(c==0) ans+=a[r];
				else{
					ans+=p;
				}
			}
			r--;
			p-=a[r];
			c=0;
		}
		else{
			if(b[l]!=b[r])
			ans+=min(a[l],a[r]);
			l++;
			r--;
			p+=b[l]-b[r];
			if(a[l]>a[r]) c=0;
	        else c=1;
		}
	}
	cout<<ans;
	return 0;
}
