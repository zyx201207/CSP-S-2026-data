#include<bits/stdc++.h>
using namespace std;
int a[500005],b[20005][20005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n&&i<20005;i++){
		for(long long j=0;j<i;j++){
			b[i][j]=a[i]-a[j];
		}
	}
	long long mxans=-1;
	for(long long i=1;i<n&&i<260005;i++){
		long long j=1;
		long long cnt=0;
		while(i>=j){
			if((cnt+b[i][i-j])<=m){
				cnt+=b[i][i-j];
				j++;
			}
			else{
				break;
			}
		}
		if(j>mxans) mxans=j;
	}
	cout<<mxans;
	return 0;
}
