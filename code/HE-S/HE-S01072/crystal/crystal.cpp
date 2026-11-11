#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m;
long long ans=0;
long long jc(int mid){
	long long ans=0;
	long long i;
	for(i=mid;i>=0;i--){
		ans+=(a[mid]-a[i]);
		if(ans>m){
			break;
		}
	}
	return mid-i;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	if(n<=10000){
		for(int i=1;i<=n;i++){
			ans=max(ans,jc(i));
		}
		cout<<ans;
		return 0;
	}
	
	while(l<r){
		int mid1=l+ceil((r-l)*1.0/3);
		int mid2=l+ceil((r-l)*1.0/3)*2;
		if(jc(mid1)>=jc(mid2)){
			r=mid1;
			ans=max(ans,jc(mid1));
		}
		else{
			l=mid2;
			ans=max(ans,jc(mid2));
		}
	}
	cout<<ans;
	//考三分，我还没看，给了给了。调半天只过前三个样例，第四个样例只能放了。后面题由于T1没看，就这样吧。
	//好像去年的卡帕瓦是安平志臻的zym，希望上一下迷惑行为大赏吧
	//有不甘吗，有的，但又能怎样呢 
}
