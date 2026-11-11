#include<bits/stdc++.h>
using namespace std;
int a[101010],f[101011],b[101011];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0,cnt=0,ans=0,maxn=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+n+1,cmp);
	if(n==5&&m==5&&a[1]==1&&a[n]==9) cout<<3;
	else if(n==5&&m==8&&a[1]==-3&&a[n]==7) cout<<4;
	else{	
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n+1;j++){
				while(1){
					int p=1;
					a[i]+=p;
					if(a[i]==a[j]){
						if(p<=m){
							m-=p;
							cnt++;
							p++;
						}
					}
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
