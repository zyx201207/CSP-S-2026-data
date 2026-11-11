#include<bits/stdc++.h>
using namespace std;
long long n,m,num,a[500001],b[500001][500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long Max=0;
	for(long long i=2;i<=n;i++){
		long long num=0,cnt=0;
		for(int j=1;j<=i;j++){
			b[i][j]=a[i]-a[j];
			if(m-num-b[i][j]>=0){
				num+=b[i][j];
				cnt++;
			}
		}
		Max=max(Max,cnt);
	}
	cout<<Max<<endl;
	return 0;
} 
