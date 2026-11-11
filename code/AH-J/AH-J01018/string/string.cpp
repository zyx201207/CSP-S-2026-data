#include<bits/stdc++.h>
using namespace std;
int n;
int l=1,r=n;
long a[200010];
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r){
		
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++,r--;
			}
		}else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				l++,r--;
			}
			//cout<<"ok"<<l<<r<<endl;
		}
	}
	cout<<ans;
	return 0;
}
/*
6
10000000000 a
10000000000 a
10000000000 a
10000000000 b
10000000000 b
10000000000 b
*/
