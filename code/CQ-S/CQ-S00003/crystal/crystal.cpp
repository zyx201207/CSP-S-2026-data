#include <bits/stdc++.h>
using namespace std;

int a[500005];

bool cmp(int x,int y){
	return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		sort(a+1,a+n+1); 
		int num=1,maxx=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]) num++;
			if(a[i]!=a[i-1]){
				maxx=max(maxx,num);
				num=1;
			}
		}
		cout<<maxx;
		return 0;
	}
	int ans=0,cnt=0;
	if(a[2]-a[1]==1&&a[3]-a[2]==1){
		for(int i=1;i<=n;i++){
			if(ans<=m){
				ans+=i;
				cnt++;
			}
			else{
				cout<<cnt;
				return 0;
			}
		}
	}
	int b[500005];
	long long l=a[2]-a[1];
	long long ll=a[3]-a[2];
	long long lll=a[4]-a[3];
	if(l==ll&&ll==lll){
		for(int i=1;i<=n;i++){
			ans+=i*l;
			cnt++;
			if(ans>m){
				cout<<cnt;
				return 0;
			}
		}
	}
	cout<<m/2+1;
	return 0;
}
