#include <bits/stdc++.h>
using namespace std;

const int maxn=500010;
int n;
long long m;
long long a[maxn];
long long cnt[maxn]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	
	if(m==0){
		for(int i=0;i<n;i++){
			cnt[a[i]]++;
		}
		int ma=cnt[0];
		for(int j=0;j<n;j++){
			if(cnt[j]>ma){
				ma=cnt[j];
			}
		}
		cout<<ma;
		return 0;
	}
	
	int d=a[1]-a[0];
	int t=d;
	int ans=1;
	while(m>=d&&ans<n){
		m-=d;
		d+=t;
		ans++;
	}
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

