#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[200005],n;
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n,cnt=0;
	while(true){
		if(l>=r){
			break;
		}
		if(a[l]<a[r]){
			if(s[l]!=s[r]) cnt+=a[l];
			a[r]-=a[l];
			l++;
		}else if(a[l]==a[r]){
			if(s[l]!=s[r]) cnt+=a[l];
			a[l]=a[r]=0;
			l++;
			r--;
		}else if(a[l]>a[r]){
			if(s[l]!=s[r]) cnt+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<cnt;
}//Trick||Treat!
