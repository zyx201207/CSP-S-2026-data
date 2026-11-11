#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long c=m;
    long long n1[500005]={};
    long long a[500005]={},b=0;
    for(long long i=1;i<=n;i++){
		cin>>n1[i];
	}
	if(m==0){
        for(long long i=1;i<=n;i++){
            b=0;
            for(long long j=1;j<=n;j++){
                if(n1[i]==n1[j]){
                    b++;
                }
            }
            a[i]=b;
        }
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
	}
	sort(n1+1,n1+1+n);
	for(long long i=1;i<=n;i++){
		b=0;
		m=c;
		for(long long j=1;j<=i;j++){
            if(n1[i]==n1[j]){
                b++;
            }else{
                if(n1[i]-n1[j]<=m){
                    m=m-n1[i]+n1[j];
                    b++;
                }
            }
	    }
	    a[i]=b;
	}
	sort(a+1,a+1+n);
	cout<<a[n];

    return 0;
}
