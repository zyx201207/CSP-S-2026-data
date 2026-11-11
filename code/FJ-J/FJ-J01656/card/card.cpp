#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],s[500000],l[500000];
set<long long>e;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin>>n>>m;
	cin>>a[1];
	e.insert(a[1]);
	l[a[1]]=1;
	for(int i=2;i<=m;i++){
		 cin>>a[i];
		if(e.count(a[i])==1){
			 for(int i=l[a[i]];i<=i-1;i++){
			 	a[i]==0;s
			 }
		}
	}
	return 0;
}
