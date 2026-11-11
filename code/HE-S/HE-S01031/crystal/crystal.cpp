#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000];
long long cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=a[(1+n)/2];
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=n;j++){
			if(a[j]==s){
				cnt++;
				break;
			}
			else if(a[j]<s){
				a[j]++;
				m--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
