#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,i,m,maxx,sum,b[N];
long long a[N],c[N];
int x[N][30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		if(a[j]>=maxx)  maxx=a[j];
	}
	while(maxx>0){
		maxx/=2;
		sum++;
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
		int num=sum;
		c[j]=a[j];
		while(a[j]>0){
			if(a[j]%2==0)  x[j][num]=0;
			else  x[j][num]=1;
			a[j]/=2;
			num--;
		}
	}
	for(int j=1;j<=sum;j++){
		int k=0;
		for(int i=1;i<=n;i++)
			if(x[i][j]==1)
				k++;
		if(k>=m){
			int num2=0;
			for(int i=n;i>=1;i--){
				if(x[i][j]==1){
					b[num2]=i;
					num2++;
				}
				if(num2==m)
					break;
			}
			break;
		}
	}
	int f;
	for(f=1;f<m;f++)
		c[b[f]]&=c[b[f-1]];
	cout<<c[f];
	return 0;
}
