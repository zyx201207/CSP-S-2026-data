#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a,long long b){
    return a>b;
}
long long crst[10000999];
int main(){
    freopen("/home/noi/noip/HE-S00635/crystal/crystal.in","r",stdin);
    freopen("/home/noi/noip/HE-S00635/crystal/crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>crst[i];
    }
    sort(crst,crst+n,cmp);
    long long maxn=1;
	for(int i = 0;i<n;i++){
		long long ljq = 1,tms = m;
		for(int j = i+1;j<n;j++){
			if(crst[i]-crst[j]<=tms){
				ljq++;
				tms-=crst[i]-crst[j];
			}
			else{
				break;
			}
		}
		maxn = max(maxn,ljq);
	}
	cout<<maxn;
    return 0;
}
