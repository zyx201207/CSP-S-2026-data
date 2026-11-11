#include<bits/stdc++.h>
using namespace std;
long long n,sc,sum;
struct node{
	long long g;
	char sym;
}a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].sym;
		sc+=a[i].g;
	}
	long long mid=sc/2+1,k=1,j=1,zj=1;
	for(int i=1;i<=mid;i++){
		if(j>a[k].g){
			k++;
			j=1;
		}
		long long dj=0;
		char l;
		for(int q=n;q>n/2;q--){
			dj+=a[q].g;
			if(dj>=zj){
				l=a[q].sym;
				break;
			}
		}
		if(a[k].sym!=l)
			sum++;
		j++;
		zj++;
	}
	cout<<sum;
	return 0;
}
