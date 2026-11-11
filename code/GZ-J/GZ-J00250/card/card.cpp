//GZ-J00250 贵阳市新世界学校 李宗运
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long a[N],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long r[m+5];
	for(int i=0;i<=n;i++){
		long long c[m+5],q[n+5],len=0;
		for(int j=1;j<=m;j++)c[j]=0;
		for(int j=i+1;j<=n;j++){
			if(c[a[j]]!=0){
				for(int k=1;k<=len;k++){
					if(q[k]==a[j]){
						for(int w=k+1;k<j;k++)c[a[w]]=0;
						len=k;
					}
				}
			}
			else {
				len++;
				c[a[j]]+=1;
				q[len]=a[i];
			}
		}
		for(int i=1;i<=len;i++)r[q[len]]++;
	}
	for(int i=1;i<=m;i++)cout<<r[i]<<' ';
	return 0;
}
