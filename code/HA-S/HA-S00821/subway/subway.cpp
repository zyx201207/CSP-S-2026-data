#include <bits/stdc++.h>
using namespace std;
    int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	int a[500];
	long long st,en;
	long long t;
	long long i[500050];
	long long ans;
	long long zhanshu;
	int  l[500050];
	long long f; 
	cin>>c>>n>>m>>d>>q;
    cin>>l[d];
    cin>>t;
    cin>>st>>en;
    long long j = en-st;
    for(long long i = 0;i<j;i++){
            zhanshu = t*j;
    }
    for(int k=0;k<=q;k++){
            ans = zhanshu *(d+f);
    }
    cout<<ans;
	return 0;
    }
