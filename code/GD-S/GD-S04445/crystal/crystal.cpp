#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=0;
	int abc;
	cin>>n;
	cin>>m;
	long long a[n+10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]-a[1]<=n){
	
	for(long long i=a[1];i<=a[n];i++){
		long long tmp=m,sum=0;
		long long j=0;
		while(a[j]<=i)j++;
		j--;
		if(j>0) abc=j; 
		for(;j>=1 && tmp>0;j--){
			if(tmp>=(i-a[j])){
				tmp=tmp-(i-a[j]);
				sum++;
			}
			else break;
		}
		maxn=max(maxn,sum);
	}
}
	else{
	for(int i=1;i<=n;i++){
		long long tmp=m,sum=0;
		for(int j=i;j>=1 && tmp>0;j--){
			if(tmp>=(a[i]-a[j])){
				tmp=tmp-(a[i]-a[j]);
				sum++;
			}
			else break;
		}
		maxn=max(maxn,sum);
	}
}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
