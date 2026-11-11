//I will ACT1
//I will have S3+
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long s=a[n/2+1]; 
	for(int i=1;i<=n;i++){
		if(a[i]<=s){
			a[i]++;
			m--;
		}
		if(m==0){
			break;
	}
	for(int i=1;i<=n;i++){
			if(a[i]==s){
			ans++;
		}
	}
			cout<<ans;
			return 0;
	}
}
//.
