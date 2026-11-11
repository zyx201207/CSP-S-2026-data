#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N],l=1,r,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}while(l<r){
		if(l>=r) break;
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]==a[r]){
				l++;
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}//cout<<"when l="<<l<<" r="<<r<<" ,the ans is "<<ans<<endl;
	}cout<<ans;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
