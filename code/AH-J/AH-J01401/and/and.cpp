#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long ans;
int mm[400010];
int kk[200005];
bool pd(int i){
	while(i>1){
		if(i%2){
			return 0;
		}
		i/=2;
	}
	return 1;
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout <<a[n];
		return 0;
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout <<ans; 
		return 0;
	}
	if(m==2){
		int aa=1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				mm[aa++]=a[i]&a[j];
			}
		} 
		sort(mm+1,mm+1+n);
		cout <<mm[n];
		return 0;
	}
	if(pd(n)){
		int cnt=1;
		for(int i=1;i<=n;i++){
			bool tmp=pd(a[i]+1);
			if(tmp){
				kk[cnt++]=a[i];
			}
		}
		sort(kk+1,kk+cnt); 
		if(cnt>=m){
			cout <<kk[cnt-m];
		}
		return 0;
	}
	if(m==n-1){
		int max=0;
		for(int i=1;i<=n;i++){
			ans=(i==1)?2:1;
			for(int j=1;i<=n;i++){
				if(j==i){
					continue;
				}
				ans&=a[i];
			}
			if(a[i]>max){
				max=a[i];
			}
		}
		cout <<max;
	}
	return 0;
}
