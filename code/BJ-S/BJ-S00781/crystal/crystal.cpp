#include<bits/stdc++.h>
using namespace std;
long long a[500005],qzh[500005];
int ans=1;
long long n,m;
bool check(int x){
    for(int i=x-1;i<n;i++){
        if(m+(qzh[i+1]-qzh[i-x+1])-x*a[i]>=0){
                //cout<<"|"<<x<<" "<<i<<" "<<m+(qzh[i+1]-qzh[i-x+1])-x*a[i]<<"|";
                return true;
        }
    }
    return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		qzh[i+1]=qzh[i]+a[i];
	}
	int l=0,r=n+1,mid=(n+1)/2;
	while(l<r-1){
        mid=(l+r)/2;
        //cout<<l<<' '<<r<<endl;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
	}
	cout<<l;
	return 0;
}
