#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N],k;
bool cmp(long long aa,long long bb){
	return aa>bb;
}int main(){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>a[1];
    k=a[1];
    for(int i=2;i<=n;i++){
    	cin>>a[i];
    	k&=a[i];
	}if(m==n)
	cout<<k;
	else{
		sort(a+1,a+1+n,cmp);
		long long d=a[1];
		for(int i=2;i<=m;i++){
			d&=a[i];
		}cout<<d;
	}cout.flush();
    return 0;
}
