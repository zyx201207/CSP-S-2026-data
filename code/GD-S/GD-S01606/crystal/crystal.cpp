#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],b[MAXN];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ansa=a[n/2+1];
	long long ans=0;
	long long o=1;
	for(int i=1;i<=n;i++){
		if(a[i]==ansa){
			ans++;
		}
	}
	while(m>=0){
		if(a[o]<ansa){
			a[o]++;
			m--;
		}
		if(a[o]==ansa){
			ans++;
			o++;
		}
		if(m==0){
			break;
		}
	}
	cout<<ans;
	return 0;
} 
