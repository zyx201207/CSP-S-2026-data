#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long cnt=0,st,b,zj;
	long long l[200050],a[200050],x[200050];
	string k,y;
	cin>>b;
	for(int i=1;i<b;i++){
        cin>>a[i]>>k[i];
        st=st+a[i];
        l[i]=a[i]+a[i-1];
        x[i]=a[i];
        y[i]=k[i];
	}
	if(st%2 == 0) {
        zj=lower_bound(l,l+b+1,st/2)-l;
        for(int i=1;i<b;i++){
            if(i<zj){
                x[b-i+1]=x[i];
                y[b-i+1]=y[i];
            }
        }
        for(int i=1;i<b;i++){
            if(k[i] != y[i]) cnt=cnt+x[i];
        }
	}
	cout<<cnt;

	return 0;
}
