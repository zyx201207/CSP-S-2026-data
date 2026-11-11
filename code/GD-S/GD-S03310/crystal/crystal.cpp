#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,qvq=1;long long m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			qvq=0;
			break;
		}
	}
	if(qvq==1){
		int l=0;
		while(m>0){
		    l++;
			m=m-l*(a[2]-a[1]);
			if(l>=n){
				l=n;break;
			}
		}
		cout<<l;
		return 0;
	}
	int l=0,sum=0;
	for(int i=1;i<=n;i++){
		int k=m;
		l=0;
		while(a[i]-a[i-l]<=k&&i>l){
			k=k-a[i]+a[i-l];
			l++;
		}
		sum=max(l,sum);
	}
	cout<<sum;
} 
