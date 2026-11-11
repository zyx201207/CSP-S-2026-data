#include<bits/stdc++.h>
using namespace std;
int n,ans,a[200001],c[200001],i;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	do{
		if(c[l]==c[r]){
			if(a[l]>a[r]){a[l]-=a[r];r++;}
			else if(a[l]<a[r]){a[r]-=a[l];l++;}
			else{r++;l++;}
		}
		else{
			if(a[l]>a[r]){ans+=a[r];a[l]-=a[r];r++;}
			else if(a[l]<a[r]){ans+=a[l];a[r]-=a[l];l++;}
			else{ans+=a[l];r++;l++;}
		}
	}while(l==r or(a[l]==0 and a[r]==0));
	cout<<ans;
	return 0;
}
