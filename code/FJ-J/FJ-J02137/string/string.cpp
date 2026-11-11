#include<bits/stdc++.h>
using namespace std;
long long lef,rig,n,ans;
struct word{
	long long num;
	char c;
};
word a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	lef=1,rig=n;
	while(lef<rig){
		if(a[lef].c!=a[rig].c){
			if(a[lef].num>a[rig].num){
				ans=ans+a[rig].num;
				a[lef].num-=a[rig].num;
				--rig;
			}else if(a[lef].num==a[rig].num){
				ans=ans+a[lef].num;
				++lef;
				--rig;
			}else{
				ans+=a[lef].num;
				a[rig].num-=a[lef].num;
				++lef;
			}
		}else{
			if(a[lef].num>a[rig].num){
					a[lef].num-=a[rig].num;
					--rig;
				}else if(a[lef].num==a[rig].num){
					++lef;
					--rig;
				}else{
					a[rig].num-=a[lef].num;
					++lef;
				}
		}
	}
	cout<<ans;
	return 0;
}
