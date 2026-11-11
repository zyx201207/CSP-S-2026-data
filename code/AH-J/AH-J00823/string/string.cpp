#include<bits/stdc++.h>
using namespace std;
char s;
long long n,i,a[200010],b[200010],l,r,cnt,ans,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cin>>s;
		t=s-'a'+1;
		b[i]=t;
	}
	while(1){
		ans=r-l;
		if(ans<=0){
			cout<<cnt;
			break;
		}
		if(a[l]>a[r]){
			a[l]=a[l]-a[r];
			if(b[l]!=b[r]){
				cnt+=a[r];
			}
			r--;
		}else if(a[l]<a[r]){
			a[r]=a[r]-a[l];
			if(b[l]!=b[r]){
				cnt+=a[l];
			}
			l++;
		}else{
			if(b[l]!=b[r]){
				cnt+=a[l];
			}
			l++;
			r--;
		}
	}
	return 0;
}
