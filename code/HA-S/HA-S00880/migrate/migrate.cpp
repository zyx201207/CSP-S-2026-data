#include<bits/stdc++.h>
using namespace std;
const int N=50001;
int m,n,maxn=-99999,a[N],cnt,l;
int f[N];


int main(){
	/*freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);*/
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	int u=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	sort(a,a+n);
	cnt=1;
	for(int i=2;i<=n;i++){
		cnt=1;
		if(a[i]==a[i-1]){
			
			cnt++;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==a[j-1]){
					cnt++;
					if(j==n){
						for(int k=i-1;k<=j;k++)
						{
							f[k]=cnt;
						
						}
						i=j;
						j=n+1;

					}
				}
				if(a[j]!=a[j-1]){
					for(int k=i-1;k<=j-1;k++)
					{
						f[k]=cnt;
						
					}
					i=j;
					j=n+1;
					
				}
			}
			if(maxn<=cnt)	maxn=cnt;
		}
	}
	
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	for(int i=2;i<=n;i++)
	{
		m=u;
		cnt=f[i];
		for(int j=i-1;j>=1;j--){
			
			
			if(m>=(a[i]-a[j])&&(a[i]-a[j]!=0)){
				m-=(a[i]-a[j]);
				cnt++;
			}
			else
			{
				if(maxn<=cnt)	maxn=cnt;
				j=0;
			}
			if(maxn<=cnt)	maxn=cnt;
		}
	}
	cout<<maxn<<endl;
	return 0;
}
