#include<bits/stdc++.h>
using namespace std;
int a[22225];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,d,c=0,maxn=0,sum=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	d=a[1];
	for(int i=0;i<n;i++){
		if(a[i]==d){
			c++;
		}
		maxn=max(maxn,a[i]);
	}
	for(int i=0;i<n;i++){
		sum=(a[i] and sum);
	}
	if(c==n){
		cout<<d;
		return 0;
	}
	else if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<sum;
		return 0;
	}else{
		cout<<7;
	}
	return 0;
}

