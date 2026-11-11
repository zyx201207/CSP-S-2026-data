#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
long long num[N];
bool ok(int ans){
    //cout<<ans<<"------"<<endl;
	if(ans==0||ans==1)return 1;
	for(int i=1;i<=n-ans+1;i++){
		long long t=num[ans+i-1]-num[i]- (a[ans+i-1]-a[i])*(i-1);
		//cout<<t<<" ";
        if(t<=m)return 1;
	}//cout<<endl;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num[i]=(a[i]-a[i-1])*(i-1)+num[i-1];
//		cout<<num[i]<<" ";
	}
//	cout<<endl;
	int l=0,r=n,mid;
	int time=0;
	while(l<r){
		time++;
		mid=(l+r)/2;
		if(ok(mid)==1){
			if(ok(mid+1)==0){
				cout<<mid;
				break;
			}
			l=mid;
		}
		else{
			r=mid;
		}
		//cout<<mid<<endl;
		if(time==1e3){
			cout<<1;
			return 0;
		}
	}
	return 0;
}
