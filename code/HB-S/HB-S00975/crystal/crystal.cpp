#include <bits/stdc++.h>
using namespace std;
const int MAXX=100000000+5;
int o[MAXX];
int st[MAXX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int o[n],st[n];
	for(long long i=0;i<n;i++){
		cin>>o[i];
	}
	sort(o,o+n);
	st[0]=o[0];
	for(long long i=1;i<n;i++){
		st[i]=st[i-1]+o[i];
		if(st[i]+m<(i+1)*o[i]){
			cout<<i;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
