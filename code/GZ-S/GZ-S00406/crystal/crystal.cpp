//GZ-S00406 遵义市南白中学 赵宇航  
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll a[maxn],cf[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	ll n,m;
	bool flag=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	stable_sort(a,a+n);
	for(int i=1;i<n;i++){
		cf[i]=a[i]-a[i-1];
	}
	for(int i=2;i<n;i++){
		if(cf[i]!=cf[i-1])flag=0;
	}
	ll head=0,tail=0,temp=0,ans=0;
	if(flag){
		int d=cf[2],i=1;
		while(m>=0){
			m=m-d*i;
			i++;
		}
		cout<<i-1;
		return 0;
	}
	
	for(;tail<n&&head<=tail;){
		temp+=(a[tail+1]-a[tail])*(tail-head);
		if(temp<=m){
			tail++;
			ans=max(ans,tail-head);
		}else{
			if(a[tail+1]-a[tail]>m){
				head=tail+1;
				tail++;
				temp=0;
			}else{
				while(temp>m){
					temp=temp-(a[tail]-a[head++]);
				}
				
			}
		}
//		cout<<"------"<<temp<<"-----"<<'\n';
	}
	cout<<ans+1;
	return 0;
}
