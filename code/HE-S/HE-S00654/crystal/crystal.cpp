#include <bits/stdc++.h>
using namespace std;
const int N=1e8;
long long n,m,a[N],b=0,sum=0,ans=0,num=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	a[n+1]=1e8;
	for(int i=1; i<=n; i++){
		if(a[i+1]<a[i]){
			b=a[i+1];
			a[i+1]=a[i];
			a[i]=b;
		}
	}
	for(int j=1; j<=n; j++){
		for(int i=1; i<=j; i++){
			if(sum>=m){
				break;
			}
			while(a[i]<a[i+1]){
				a[i]+=1;
				sum++;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(a[i]==a[i+1])
		{
			num++;
		}
	}
	cout<<num;
	return 0;
}
