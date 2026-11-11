#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,sum,a[500005],b[500005];
int f[500005];
set<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int k=1;k<=m;k++){
		for(int i=k;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(f[i]==0)f[i]=1;
				if(f[j]==0)f[j]=1;
				if(a[i]==a[j]){
					for(int l=i;l<j;l++){
						f[l]=2;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(f[i]==1)s.insert(a[i]);
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=s.size();i++){
			if(s.count(j))b[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
