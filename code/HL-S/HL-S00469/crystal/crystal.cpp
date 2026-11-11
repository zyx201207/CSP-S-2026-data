#include<bits/stdc++.h>
using namespace std;
struct sj{
	long long x;
	long long y;
}k[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long s[n+1][n+1]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			s[i][j]=a[i]-a[j];
		}
	}
	long long sum=0,cnt=1;
	for(int i=1;i<=n;i++){
		sum=0;
		cnt=1;
		for(int j=1;j<i;j++){
			if(s[i][j]>0){
				cnt++;
				sum+=s[i][j];
			}
			else if(a[i]==a[j]){
				cnt++;
			}
		}
		k[i].x=sum;
		k[i].y=cnt;
	}
	long long p=0;
	for(int i=1;i<=n;i++){
		if(k[i].x<=m){
			p=max(p,k[i].y);
		}
	}
	cout<<p;
	return 0;
}
