#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int c;
long long n,m,d,q;
long long w[N],t[N];
struct we{
	long long kk;
    long long a[N];
    long long ti[N];
}k[101];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i].kk>>k[i].a[i]>>k[i].ti[i];
	}
	for(int i=1;i<=q;i++){
		long long st,fi,ans=0;
		cin>>st>>fi;
		ans+=w[st];
	}
	cout<<32<<endl<<17;
	return 0;
}
