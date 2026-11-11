#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],b[500010];
bool cmp(long long x,long long y){
	return x>y;
}
bool cmp2(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[1]-a[0]==a[2]-a[1]){
		int ans=0;
		for(int i=1;i<n;i++){
			if(m>=abs(a[1]-a[0])*i){
				m-=abs(a[1]-a[0])*i;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	sort(a,a+n,cmp);
	int cnt=0;
	for(int i=0;i<n-1;i++){
		b[cnt]=a[i]-a[i+1];
		cnt++;
	}
	sort(b,b+cnt,cmp2);
	int ans=0;
	for(int i=0;i<cnt;i++){
		if(m>=b[i]){
			if(b[i]==0) ans++;
			ans++;
			m-=b[i];
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
