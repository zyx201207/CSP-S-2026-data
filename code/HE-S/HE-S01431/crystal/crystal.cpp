#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,m,a[N],sum=0,num=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long cha[n] = {0};
	for(int i=0;i<n-1;i++){
		cha[i] = a[i+1] - a[i];
	}
	sort(cha, cha + n - 1);
	int i=0;
	while(sum<=m){
		num++;
		sum += cha[i];
		i++;
		if(sum+cha[i]>m){
			break;
		}
	}
	cout<<num;
	return 0;
 }
