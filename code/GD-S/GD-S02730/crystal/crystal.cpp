#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<ll>a(n+5);
	vector<ll>b(n+5);
	int mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int ans;
	for(int i=2;i<=n;i++){
		sum=0;mm=m;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		int ii=a[i];
		for(int j=i-1;j>=0;j--){
			if(mm==0)break;
			while(mm>0 && b[j]<ii){
				mm--;
				b[j]++;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]==ii)sum++;
		}
		if(ans<sum)ans=sum;
	}
	cout<<ans;
	return 0;
}
