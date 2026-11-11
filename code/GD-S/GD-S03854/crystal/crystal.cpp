#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int sum=-1;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=a[1];i<=a[n];i++){
		int b=n,ans=0;
		for(int j=1;j<=n;j++){
			if(a[j]>i){
				b=j-1;
				break;
			}
		}
		long long a1[n+5];
		for(int j=1;j<=n;j++){
			a1[j]=a[j];
		}
		long long m1=m;
		while(m1>0){
			if(a1[b]==i){
				ans++;
				b--;
				continue;
			}
			if(i-a1[b]<=m1){
				b--;
				m1-=i-a1[b];
				ans++;
			}
			else{
				break;
			}
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
	}
