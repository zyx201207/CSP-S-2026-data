#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);//🕒😍🥧🥌⌛✒
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}   
	for(int i=1;i<=m;i++){
		a[i]+=1;
		m--;fg
		for(int j=i;j<=m;j++){
			a[j]+=1;
			m--;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long cnt=0;
			if(a[j]==a[i]){
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
