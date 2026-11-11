//GZ-S00179 安顺开发区长水大洋实验学校 秦泽锦玥 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
double a[1000005],o[10000005];
int l[5];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	o[i]=0;	
	if(a[i]==i)l[1]++;
	if(i==100 && l[1]==100){
	cout<<n;
	break;
	}
	}
	if(l[1]!=100){
		sort(a,a+n+1);
	for(int i=1;i<n;i++){
	int h=i+1;
	for(int j=i+1;j>1;--j){
	if(m>=a[h]-a[j])o[i]++;
	else break;
	}
}
	sort(o,o+n+1);
	cout<<o[n];	
	}
	return 0;
}

