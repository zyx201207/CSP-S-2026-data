#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	ll sum3=0,sum4=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=n)sum4+=a[i];
	}
	sort(a+1,a+n+1);
	sum3=a[n]*n-sum4;
	if(sum3<=m){
		cout<<n<<endl;
		return 0;
	}
	int ans=1,id=1;
	ll res=0;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			ll sum=0;
			for(int j=i+1;j<n;j++){
				if(sum+a[j]-a[i]>m){
					ans=max(ans,j-i);
					break;
				}
				sum=sum+a[j]-a[i];
			}
		}
	}
	else{
		bool op=true;
		ll cha=a[n]-a[n-1];
		for(int i=n-1;i>=1;i--){
			if(a[i+1]-a[i]!=cha)op=false;
			res+=a[n]-a[i];
			if(res>m){
				res=res-a[n]+a[i];
				id=i+1;
				break;
			}
		}
		if(op==true){
			ll summ=0;
			for(int i=1;i<=n;i++){
				summ+=1LL*cha*i;
				if(summ>m){
					cout<<i;
					return 0;
				}
			}
		}
		ans=ans+n-id;
		//cout<<res<<"  "<<ans<<"  "<<id<<endl;
		for(int i=n-1;i>ans;i--){
			res=res-(a[i+1]-a[i])*(i-id);
			if(i==id)res=0;
			if(id==0){
				cout<<ans;
				return 0;
			}
			//cout<<i<<"  "<<res<<"  "<<ans<<"  "<<id<<" "<<i-id+1<<endl;
			while(res+a[i]-a[id-1]<=m&&id>1){
				res+=a[i]-a[--id];
				ans=max(i-id+1,ans);
				//cout<<i<<"  "<<res<<"  "<<ans<<"  "<<id<<" "<<i-id+1<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
7 12
-3 -1 3 4 8 10 15
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 8
1 2 3 4 5
6 15
2 5 8 11 14 17
4 100
1 2 3 4
*/