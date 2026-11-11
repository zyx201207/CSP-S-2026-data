#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
long long ans;
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]) f=0;
	} 
	if(f){
		cout<<'0';
		return 0;
	}
	int l=1,r=n;
	while(l<=n&&r>=0&&r>l){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			if(a[l]>=a[r])a[l]-=a[r],a[r]=0;
			else a[r]-=a[l],a[l]=0;
		}
		else{
			if(a[l]!=a[r]){
				if(a[l]>=a[r]) a[l]-=a[r],a[r]=0;
				else a[r]-=a[l],a[l]=0;
			}
			else l++,r--;
		} 
	}
	cout<<ans;
	return 0;
}//后面3个大样例没过可我现在怎么调都调不出来啊啊啊
//只能求RP++了，希望没啥大事
//希望没啥大事听到了没有 
