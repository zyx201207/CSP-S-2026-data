#include<bits/stdc++.h>
using namespace std;
long long a[500005],t[500005],mx=0,n,m,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=0,f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
		if(a[i]!=i)
			f=1;
	}
	long long cnt;
	if(n>=2){
		cnt=a[2]-a[1];
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cnt)
			f1=1;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long h=a[i],q=m;
			sum=0;
			//重置a数组
				for(int j=1;j<=n;j++){
					a[j]=t[j];
				}
			//
			for(int j=1;j<=n;j++){
				a[j]=abs(h-a[j]);
			}
			sort(a+1,a+n+1);
			for(int j=1;j<=n;j++){
				if(q>=a[j]){
					q-=a[j];
					sum++;
				}
			}
			mx=max(mx,sum);
		}
		cout<<mx;
	}
	else if(!f){//特殊性质 A
		long long k=1;
		while(k<=n){
			for(int p=1;p<=2;p++){
				if(m>=k){
					sum+=1;
					m-=k;
				}
				if(m<k){
					cout<<sum+1;
					return 0;
				}
			}
			k++;
		}
		
	}
	else if(!f1){//特殊性质 b
		long long k=cnt;
		while(k<=n){
			for(int p=1;p<=2;p++){
				if(m>=k){
					sum+=1;
					m-=k;
				}
				if(m<k){
					cout<<sum+1;
					return 0;
				}
			}
			k+=cnt;
		}
	}
	return 0;
}
/*
8 9
1 2 3 4 5 6 7 8

5 8
-3 -1 2 2 7

1 5
32
Oct31==Dec25?
*/
