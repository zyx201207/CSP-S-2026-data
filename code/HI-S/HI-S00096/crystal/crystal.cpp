#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int n,m,ans,gong_cha;
int chu_li(int pos){
	int mid=a[pos],b=m,ans2=0;
	for(int i=pos;i>=0;i--){
		if(b-(mid-a[i])>=0){
			b-=(mid-a[i]);
			ans2++;
		}
		else{
			break;
		}
	}
	return ans2;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	bool flag=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	gong_cha=a[n-1]-a[n-2];
	for(int i=n-3;i>=0;i--){
		if(a[i]-a[i-1]!=gong_cha){
			flag=0;
			break;
		}
	}
	if(m==0){
		ans=1;
	}
	else if(flag){
		for(int i=0;i<n;i+=gong_cha){
			m-=i;
			ans++;
			if(m<0){
				break;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			ans=max(chu_li(i),ans);
		}
	}
	cout<<ans;
	return 0;
}
