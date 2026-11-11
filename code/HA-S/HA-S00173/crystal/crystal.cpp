#include<bits/stdc++.h>
using namespace std;
const int N=19999900;
int n;
long long a[N],m;
int maxn=1,sum=0,minn=500001,k=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
		if(a[i]<minn){
			minn=a[i];
		}
		
	}
	for(int i=0;i<=n;i++){
		int v=0;
		v=maxn-abs(a[i]);
		k+=v;
		if(a[i]==a[i++]){
			sum++;
		}
		
		
	}
	if(k>=maxn*2){
		cout<<n;
	}
	else if(m==0){
		cout<<sum;
	}
	return 0;
}
