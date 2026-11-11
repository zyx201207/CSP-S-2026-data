#include<bits/stdc++.h>
using namespace std;
const int N=6e5+7;
int n,m,ans,cnt=0;
bool flag=0;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int t=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=t)flag=1;
	}
	if(flag==0){
		cnt=1;
		for(int i=1;;i++){
			if(m>=(i*t)){
				cnt++;
				m-=(i*t);
			}
			else break;
		}
		cout<<cnt;
	}
	else{
		int t=m;
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			cnt=0;
			t=m;
			for(int j=i-1;j>0;j--){
				int x=a[i]-a[j];
				if(x==0)continue;
				if(t>=x)t-=x,cnt++;
				else break;
			}
			cnt+=upper_bound(a+1,a+n+1,a[i])-lower_bound(a+1,a+n+1,a[i]);
			//cout<<cnt<<' ';
			ans=max(cnt,ans);
		}
		cout<<ans;
	}
	return 0;
}
