#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,num,ans,sum;
ll m,a[500005],b[500005],nn;
bool aa(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1,aa);
	for(int i=1;i<=n-2;++i)
		if(a[i]-a[i+1]!=a[i+1]-a[i+2]){
			num=1;
			break;
		}
	if(num==0){
		int k=b[1]-b[2];
		int j=k;
		ans++;
		for(int i=2;i<=n;++i){
			if(m<j)break;
			m-=j;
			j+=k;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;++i){
		sum=1;
		num=m;
		for(int i=1;i<=n;++i)b[i]=a[i];
		for(int j=i+1;j<=n;++j){
			while(b[j]!=b[i]){
				b[j]++;
				num--;
				if(num==0){
					nn=b[j];
					break;
				}
			}
			if(num==0){
				if(b[i]==nn)sum++;
				break;
			}
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
