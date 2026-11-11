#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],b[500005];
long long sum;
string s,s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			sum*=10;sum+=a[j];
			b[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			if(b[a[j]]<=0){
				b[a[j]]++;
				sum*=10;sum+=a[j];
			}
			else{
				while((sum%10)!=a[j]){
					b[sum%10]--;
					sum/=10;
				}
			}
		}
		while(sum)t[sum%10]++,sum/=10;
	}
	for(int i=1;i<=m;i++)printf("%d ",t[i]);
	return 0;
}
