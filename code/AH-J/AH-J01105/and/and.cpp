#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int cp(long long a,long long b){
	return a>b;
}
int main(){
	   freopen("and.in","r",stdin);
	   freopen("and.out","w",stdout);
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	int n,m;
    	cin>>n>>m;
    	int t=0;
    	long long x0=0,x1=0,x2=0,x3=0;
    	for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=i-1) t=1;
			if(a[i]==0) x0++;
			if(a[i]==1) x1++;
			if(a[i]==2) x2++;
			if(a[i]==3) x3++;

		}
		if(x0+x1+x2+x3==n){
			if(x3>=m){
				cout<<3;
			}else if(x3+x2>=m){
				cout<<2;
			}else if(x3+x2+x1>=m){
				cout<<1;
			}else{
				cout<<0;
			}
			return 0;
		}
		if(t==0){
			cout<<n-m;
			return 0;
		}
		sort(a+1,a+1+n,cp);
		cout<<a[m]<<endl;
		return 0;
}
