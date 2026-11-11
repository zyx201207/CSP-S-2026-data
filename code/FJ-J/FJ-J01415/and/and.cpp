#include<bits/stdc++.h>
using namespace std;
long long n,x,a[100005],ans;
bool cmp(long a,long b){
	return a>b;
}
long long lo(long long n){
	long long i=1;
	while((long long)pow(2,i)<=n){
		i++;
	}
	return (long long)pow(2,i-1);
}
long long yh(long long y1,long long y2){
	long long ans=0;
	while(y1&&y2){
		if(lo(y1)==lo(y2)){
			ans+=lo(y1);
			y1-=lo(y1);
			y2-=lo(y2);
		}
		else{
			if(y2>y1){
				y2-=lo(y2);
			}
			else{
				y1-=lo(y1);
			}
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(x==1){
		cout<<a[1];
		return 0;
	}
	if(x==2){
		cout<<yh(a[1],a[2]);
		return 0;
	}
	ans=yh(a[1],a[2]);
	for(int i=3;i<=x;i++){
		ans=yh(ans,a[i]);
	}
	cout<<ans;
	return 0;
}