#include <iostream>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	long long l=1,r=n,ls=a[1],rs=a[n],ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(ls<rs){
				rs-=ls;
				l++;
				ls=a[l];
			}
			else if(rs<ls){
				ls-=rs;
				r--;
				rs=a[r];
			}
			else{
				l++,r--;
				ls=a[l],rs=a[r];
			}
		}
		else{
			if(ls<rs){
				ans+=ls;
				rs-=ls;
				l++;
				ls=a[l];
			}
			else if(rs<ls){
				ans+=rs;
				ls-=rs;
				r--;
				rs=a[r];
			}
			else{
				ans+=ls;
				l++,r--;
				ls=a[l],rs=a[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
// J01443 OrangeSheep
