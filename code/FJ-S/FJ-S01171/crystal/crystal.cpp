#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],r,q[500005],l=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	q[1]=0;
	int L=1;
	for(long long i=2;i<=n;i++){
		q[i]=q[i-1]+(a[i]-a[i-1])*(i-L);
		if(q[i]>m){
			l=max(l,i-L);
			while(q[i]>m){
				q[i]-=a[i]-a[L];
				L++;
			}
		}
	}if(l==-1){
		cout<<n;
		return 0;
	}cout<<l;
	return 0;
}  //比J第一题还短？！ 
