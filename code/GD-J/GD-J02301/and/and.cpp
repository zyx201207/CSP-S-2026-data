#include <bits/stdc++.h>
using namespace std;
int a[(int)2e5+5];
//9:10 ÏìÁåÁË 
//9:15 ÏìÁåÁË 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int maxn=-100000,temp=0;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				temp=a[i]&a[j];
				if(maxn<temp)maxn=temp;
			}
		}
	}
	if(m==n){
		for(int i=0;i<n;i++){
			maxn&=a[i];
		}
	}
	if(m==n-1){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(j==i)continue;
				temp&=a[j];
			}
			if(maxn<temp)maxn=temp;
		}
	}
	cout<<maxn;
	return 0;
}
/* This code can get 6,7,8,9,10,11,12 ,Total 7/20,35pts.*/
