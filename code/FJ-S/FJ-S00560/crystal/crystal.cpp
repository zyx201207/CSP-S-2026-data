#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],ans=0,mans=0,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int sum=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
	for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
        	if(a[i]>a[j]){
        		a[j]=a[j]+(i-j);
        		for(int v=2;v<=n,sum>0;v++){
        			a[v]=a[v]+a[v]-i;
        			sum-=(a[v]-i);
				}
			} 
        	for(long long k=1;k<=n;k++){
        		if(a[i]==a[k]){ans++;
        		}
			}
			a[j]-=(i-j);
			a[j+1]=a[j+1]-(m-(i-j));
            mans=max(ans,mans);
            ans=0;
		}
}
	cout<<mans+1;
	return 0;
}
