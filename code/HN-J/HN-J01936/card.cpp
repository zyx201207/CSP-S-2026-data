#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[500005];
bool book[300005];
int f[300005];
int num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			if(book[j]){
				num[j]++;
				f[j]=-1;
				book[j]=0;
			}
		}
		for(int j=i;j<n;j++){
			if(book[a[j]]){
				for(int k=f[a[j]]+1;k<j;k++){
					book[a[k]]=0;
					f[a[k]]=-1;
				}
				f[a[j]]=j;
			}
			else{
				book[a[j]]=1;
				f[a[j]]=j;
			}
		}
	}
	num[a[n-1]]++;
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
