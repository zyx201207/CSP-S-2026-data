#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300050],b[300050];
long long flag[300050];
bool ilikeccf=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		if(i>1&&a[i]!=a[i-1]) ilikeccf=1;
	}
	if(!ilikeccf){
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	memset(b,0,sizeof(b));
	for(long long i=0;i<n;i++){
		memset(flag,0,sizeof(flag));
		for(long long j=i+1;j<=n;j++){
			if(flag[a[j]]){
				for(int k=flag[a[j]];k<=j;k++){
					flag[k]=0;
				}
			}
			flag[a[j]]=j;
		}
		for(long long j=i+1;j<=n;j++){
			if(flag[a[j]]){
				b[a[j]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}