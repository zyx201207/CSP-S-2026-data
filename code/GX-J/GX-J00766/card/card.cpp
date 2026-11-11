#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	else{
		int cnt=1;
		int sum=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				sum+=cnt;
				b[a[i-1]]=sum;
				cnt=1;
			}
			else
			    cnt++;
		}
		b[a[n]]=sum+cnt;
		for(int i=1;i<=m;i++)
			cout<<b[i]<<" ";
	}
	return 0;
}
