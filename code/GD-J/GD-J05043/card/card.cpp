#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i];
	}
	int cnt=n;
	for(int i=1;i<=n;i++){
		int flag=1,f=cnt;
		for(int i=1;i<=f;i++){
			if(b[i]==i)flag=0;
			if(flag==0)b[i]=0,cnt--;
		}
		b[cnt+1]=a[i],cnt++;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=cnt;k++){
				if(b[k]==j){
					c[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
} 
