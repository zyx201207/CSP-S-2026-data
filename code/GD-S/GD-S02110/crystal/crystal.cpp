#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m,a[10000001],b=0,c=0,cnt=0,big=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b=a[i];
		c=m;
		for(int j=1;j<=n;j++){
			if(a[j]<=b && c>=(b-a[j]) && j!=i){
				c-=b-a[j];
				cnt++;
			}
		}
		if(cnt>big)big=cnt;
		cnt=0;
	}
	cout<<big+1;
}
