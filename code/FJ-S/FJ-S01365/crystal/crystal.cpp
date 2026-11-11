#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		s[i]=abs(a[i]-a[i-1]);
		long long sum=0,cnt=1;
		bool flag=1;
		for(int j=2;j<=i;j++){
			sum+=s[j]*(j-1);
			if(sum>m){
				flag=0;
				break;
			}
			cnt++;
		}
		if((flag==1)&&(cnt>ans)){
			ans=cnt;
		}
	}
	cout<<ans;
	return 0;
}
