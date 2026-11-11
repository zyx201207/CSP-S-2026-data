#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500005],q[500005],t=1,cha=1,l=1,a[500005],x;
bool p=1,pp=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i>1){
			if(a[i]-a[i-1]!=x){
				pp=0;
			}
		}
        if(a[i]!=a[i-1]&&i!=1){
			p=0;
		}
		x=a[i]-a[i-1];
		
        }
    sort(a+1,a+n);
    for(int i=2;i<=n;++i){
		s[i]=a[i]-a[i-1];
		q[i]=q[i-1]+(i-1)*s[i];
		if(q[i]>m){
			;
		}else{
			t=i;
		}
	}
	if(pp)t=m/(a[2]-a[1]);
	if(p)t=n;
    cout<<t;
    return 0;
}
