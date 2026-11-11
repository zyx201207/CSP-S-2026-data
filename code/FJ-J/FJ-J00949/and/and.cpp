#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma=0;
long long cmp(long long x,long long y){
	long long i=1,l=0;
	while(x!=0&&y!=0){
		if(x%2==1&&y%2==1)l+=i;
		x/=2;
		y/=2;
		i*=2;
	}
	return l;
}

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(ma<a[i])ma=a[i];
		}
		cout<<ma;
		return 0;
	}
	if(m==n){
		cin>>ma;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ma=cmp(ma,a[i]);
			
		}
		cout<<ma;
		return 0;
	}
	if(m==n-1){
		long long k=-1;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			k=-1;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(k==-1)k=a[j];
					else k=cmp(k,a[j]);
				}
			}
			if(k>ma)ma=k;
		}
		cout<<ma;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)ma=max(ma,cmp(a[i],a[j]));
		}
	}
	cout<<ma;
	return 0;
}
