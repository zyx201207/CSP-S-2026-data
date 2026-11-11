#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long a[2000001];
long long cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cnt=0;
		for(int i=4;i<=n;i++){
			if(a[i-1]-a[i-3]<=d&&a[i]-a[i-2]<=d&&a[i]-a[i-3]>d){
				cnt++;
			}
		}
		for(int k=6;k<=n;k+=2){
			for(int i=k;i<=n;i++) 
				if(a[i-k/2]-a[i-k+1]<=d&&a[i]-a[i-k/2+1]<=d&&a[i]-a[i-k/2]<=d&&a[i-k/2+1]-a[i-k+1]<=d&&a[i]-a[i-k+1]>d){
					cnt++;
				}
		}
		cout<<cnt<<'\n';
	}
} 
