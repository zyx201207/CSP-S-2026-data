#include<bits/stdc++.h>
using namespace std;
long long zh=100000,biao,n;
struct ji{
	long long nen;
	long long cha;
}a[500005];
bool cmp(ji a,ji b){
	return a.nen<b.nen;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].nen;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		long long s=0;
		for(int j=1;j<=n;j++){
			s+=abs(a[i].nen-a[j].nen);
		}
		a[i].cha=s;
		if(zh>=a[i].cha){
			zh=a[i].cha;
			biao=i;
	}
	
	}
	cout<<biao;
	return 0;
} 
