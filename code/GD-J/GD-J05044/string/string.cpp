#include<bits/stdc++.h>
using namespace std;
struct INT{
	int num;char str;
}a[200005];
//string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;long long ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		string c;cin>>a[i].num>>a[i].str;
	}int l=1,lnow=a[1].num,r=n,rnow=a[n].num;
	while(l<r){
		if(lnow>rnow){
			if(a[l].str!=a[r].str){
				ans+=rnow;
			}r--;
			lnow=lnow-rnow;rnow=a[r].num;
		}
		else {
			if(lnow==rnow){
				if(a[l].str!=a[r].str){
					ans+=rnow;
				}l++;r--;
				lnow=a[l].num;rnow=a[r].num;
			}
			else{
				if(a[l].str!=a[r].str){
					ans+=lnow;
				}l++;
				rnow=rnow-lnow;lnow=a[l].num;
			}
		}
	}cout<<ans;
	return 0;
}
