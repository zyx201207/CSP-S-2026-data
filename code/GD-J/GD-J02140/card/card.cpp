#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL n,m;
LL a[N];
LL pai[N];
LL v[3*N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pai[a[i]]++;
	}pai[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<pai[i]<<' ';
	}
	return 0;
}

 
