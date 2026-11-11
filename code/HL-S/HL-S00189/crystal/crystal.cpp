#include <bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,x,f=1,cha;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			x=a[i];
		}
		else if(i==1){
			cha=abs(x-a[i]);
			x=a[i];
		}
		else{
			if(cha!=abs(x-a[i])) f=0;
			x=a[i];
		}
	}
	long long s=0,sum=1;
	while(s<=m){
		s+=cha*sum;
		sum++;
	}
	cout<<sum-1;
	return 0;
} 
