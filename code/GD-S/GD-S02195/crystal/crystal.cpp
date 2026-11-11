#include<bits/stdc++.h>
using namespace std;
int m,a[500005];
long long n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1);
	int maxn=0;
	for(int i=m;i>=1;i--){
		long long cnt=0,you=n;
		for(int j=i;j>=0;j--){
			long long need=a[i]-a[j];
			if(you>=need){
				you-=need;
				cnt++;
			}
			else
			{
				if(cnt>=maxn){
					maxn=cnt;
				}
				break;
			}
		}
	}
	cout<<maxn;
	return 0; 
} 
