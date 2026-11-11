#include<iostream>
using namespace std;
int a[200005],c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>a[i]>>x;
		c[i]=x-'a'+1;
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l],l++; 
			}else if(a[l]==a[r]){
				l++,r--;
			}else{
				a[l]-=a[r],r--;
			}
		}else{
			if(a[l]<a[r]){
				ans+=a[l],a[r]-=a[l],l++; 
			}else if(a[l]==a[r]){
				ans+=a[l],l++,r--;
			}else{
				ans+=a[r],a[l]-=a[r],r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

