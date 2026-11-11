#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000000];
long long ans;
bool cnt(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cnt);
	int ave=a[1]+m+1;
	int j=1;
	while(ave>=a[n]){
		ave--;
		while (a[j]>ave&&j<=n) j++;
		long long cn=0,num=0;
		for(int i=j;i<=n;i++){
			cn+=ave-a[i];
			if(cn<=m){
				num++;
				ans=max(ans,num);
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
} 
