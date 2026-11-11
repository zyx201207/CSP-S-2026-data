#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n,m,a[N],sum[N],cha;
long long ans;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cha=a[2]-a[1];
	for(int i=2;i<=n-1;i++){
		if(a[i+1]-a[i]!=cha){
			flag=true;
			break;
		}
	}
	if(!flag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=i*cha;
			if(cnt>m){
				cout<<i;
				break;
			}
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		sum[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		ans+=sum[i];
		if(ans>m){
			cout<<i;
			break; 
		}
	}
	return 0;
}
