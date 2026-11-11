#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
ll a[500005],n,ans=1,flag=0,temp=0,s,t;
unsigned long long m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag=1;
		}
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			temp=1;
		}
	}
	if(!flag){//A
		int cnt=1;
		while(1){
			if(m>=cnt){
				m-=cnt;
				ans++;
			}else{
				break;
			}
			cnt++;
		}
		cout<<ans;
		return 0;
	}else if(!temp){//B
		if(a[2]-a[1]>=0){
			s=a[2]-a[1];
			t=s;
		}else{
			s=a[1]-a[2];
			t=s;
		}
		while(1){
			if(m>=s){
				m-=s;
				ans++;
			}else{
				break;
			}
			s+=t;
		}
		cout<<ans;
	}else{
		ll cnt=1,k;
		sort(a+1,a+n+1);
		int tmp=(a[1]+a[n])/2;
		int pos=upper_bound(a+1,a+n+1,tmp)-a;
		if(pos>=((n+1)/2)){
			k=1;
		}else{
			k=pos;
		}
		while(1){
			if(a[k]==a[k+1]){
				ans++;
				k++;
				cnt++;
			}else if(m>=cnt){
				m-=cnt;
				a[k]++;
			}else{
				while(1){
					if(a[k]==a[k+1]){
						ans++;
						k++;
					}else{
						break;
					}
				}
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}

