#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct mt{
	long long m;
	char c;
}a[N];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; ++i)
		cin>>a[i].m>>a[i].c;
	long long t=0;
	for(int i=1; i<=n/2; ++i){
		if(n%2==0&&i==n/2){
			if(a[i].c!=a[i+1].c)t+=min(a[i].m,a[i+1].m);
		}
		else {
	        if(a[i].m>a[n-i+1].m){
			    if(a[i].c!=a[i+1].c)t+=a[i].m-a[n-i+1].m;
				a[i+1].m+=a[i].m-a[n-i+1].m;
		    }
			else if(a[n-i+1].m>a[i].m){
				if(a[n-i+1].c!=a[n-i].c)t+=a[n-i+1].m-a[i].m;
				a[n-i].m+=a[n-i+1].m-a[i].m;
			}
		if(a[i].c!=a[n-i+1].c)t+=min(a[i].m,a[n-i+1].m);
		}
	}
	cout<<t;
    return 0;
}
