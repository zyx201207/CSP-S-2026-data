#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int  b[300010];
long long c[300010];
int d[500010];
int sum;
int cnt;
int main(){
	/*freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);*/
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			c[a[i]]++;
			sum++;
			for(int j=1;j<i;j++){
				if(b[a[j]]!=0) c[a[j]]++;
			}
			d[a[i]]=i;
			b[a[i]]=1;
		}else{
			for(int j=1;j<=i;j++){
				c[a[j]]++;
			}
			cnt=0;
			for(int j=d[a[i]];j<sum;j++){
				b[a[j]]==0;
				cnt++;
			}
			sum-=cnt;
			d[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
