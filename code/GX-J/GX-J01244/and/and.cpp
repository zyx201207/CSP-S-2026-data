#include <bits/stdc++.h>
using namespace std;
const int MN=100000*2+5;
int num[MN];
int n,m,ma=0,k=0;
void solve(int pos,int last){
	if(pos>m){
		cout<<k<<endl;
		return;
	}
	k=num[pos];
	for(int i=last+1;i<=n;++i){
			int l=k;
			k&=num[i+1];
			cout<<num[pos]<<' '<<num[i+1]<<' '<<endl;
			if(k>ma)ma=k;
			solve(pos+1,i);
			k=l;
	}
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;++i)
	cin>>num[i];
solve(1,0);
cout<<ma;
return 0;
}
