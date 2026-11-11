#include <bits/stdc++.h>
using namespace std;
int n,m,ans=0,cnt=0,M,N,Min=0,num=0,B,C,er=1;
int a[100000000],b[10000000],c[10000000],d[10000000];
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=1;i<n;i++){
		M=a[i];
		N=a[i-1];
		ans=0;
		while (M/2!=0){
			b[ans]=M%2;
			M/=2;
			ans++;
		}

		b[ans]=M%2;
		M/=2;
		ans++;
		B=ans;
		ans=0;
		while (N/2!=0){
			c[ans]=N%2;
			N/=2;
			ans++;
		}
		c[ans]=N%2;
		N/=2;
		ans++;
		C=ans;
		Min=min(B,C);
		for (int j=0;j<Min;j++){
			if (b[j]==1 && c[j]==1){
				d[j]=1;
			}
			else{
				d[j]=0;
			}
		}
		num=0;
		for (int j=0;j<Min;j++){
			er=1;
			for (int z=0;z<j;z++){
				er*=2;
			}
			num+=d[j]*er;
		}
		if (num>cnt){
			cnt=num;
		}
	}
	cout<<cnt;
	return 0;
}
