#include<bits/stdc++.h>
using namespace std;
long long n,m,t=0,k=0;
long long d[100001];
long long a[1000001],b[1000001],c[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	while(n--){
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		k=0;
		for(int i=t;i<n;i++){
			d[k++]=a[i];
			if(b[a[i]]==0){
				b[a[i]]=i;
			}else{
				for(int j=b[a[i]];j<i;j++){
					d[j]=0;
				} 
			}
			for(int i=0;i<n;i++)c[d[i]]++;
		}
		t++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
