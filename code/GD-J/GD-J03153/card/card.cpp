#include<bits/stdc++.h>
using namespace std;
long long n,m,a[250000],s[250000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long st[250000],sum=0;
		for(int j=i;j<=n;j++){
			if(sum==0)st[1]=a[j],sum++;
			else{
				bool q=false;
				int h=0;
				for(int r=1;r<=sum;r++){
					if(!q&&st[r]==a[j])q=true;
					if(q)st[r]=0,h++;
				}
				sum-=h;
				st[sum+1]=a[j],sum++;
			}
		}
		for(int j=1;j<=sum;j++)s[st[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
