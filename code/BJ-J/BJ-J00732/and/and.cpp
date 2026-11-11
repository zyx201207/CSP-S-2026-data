#include<bits/stdc++.h>
using namespace std;
struct num{
	bool k[30],flag;
	num(){
		flag=1;
		for(int i=0;i<30;++i){
			k[i]=0;
		}
	}
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	num a[n];
	for(int i=0;i<n;++i){
		unsigned long long k;
		cin>>k;
		for(int j=0;j<30;++j){
			if(k%2){
				a[i].k[j]=1;
			}
			k/=2;
			if(!k){
				break;
			}
		}
	}
	unsigned long long ans=0,now=1;
	for(int i=0;i<29;++i){
		now*=2;
	}
	for(int i=29;i>=0;--i,now/=2){
		int cnt=0;
		for(int j=0;j<n;++j){
			if(a[j].flag&&a[j].k[i]){
				++cnt;
			}
		}
		if(cnt<m){
			continue;
		}
		ans+=now;
		for(int j=0;j<n;++j){
			if(!a[j].k[i]){
				a[j].flag=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
