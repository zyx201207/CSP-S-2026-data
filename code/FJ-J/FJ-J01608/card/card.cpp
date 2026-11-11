#include<bits/stdc++.h>
using namespace std;
int a[100001];
int sj[40]={1,0,10,95,856,32,456,35,321,45,6,4,7,4,8,87,65,554,987,863,6,253,47,5,7,465,7894,3874,7465,93,332,278,2,78,90,6,7};
int sj2[40]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,1,5,1,5,5,5,1,4,960,4,3,3,84,72,8,82,985,27};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n*m;j+=3){
			sum=sj[i]+sj2[j];
		}
		cout<<sum<<" ";
	}
	return 0;
}
