#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool t1=true;
    cin>>a[1];
    for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]-1!=a[i-1]){
			t1=false;
		}
	}
	if(t1==true){
		int r=0;
		int l=1;
		int c=0;
		for(int i=1;i<=m;i++){
			r++;
			if(r==l){
				c++;
				r=0;
				l++;
			}
		}
		if(c>=n){
			cout<<n;
			return 0;
		}else{
			cout<<c+1;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	long long maxx=0;
	for(int i=1;i<=n;i++){
		maxx=maxx+a[n]-a[i];
	}
	if(maxx<=m){
		cout<<n;
		return 0;
	}
	long long sum=0;
	for(int i=n;i>=1;i--){
		long long f=m;
		long long s=0;
		for(int j=i-1;j>=1;j--){
			f=f-a[i]+a[j];
			if(f<0){
				break;
			}
			if(f==0){
				s++;
				break;
			}
			if(f>0){
			    s++;
			}
		}
		sum=max(sum,s+1);
	}
	cout<<sum;
}
