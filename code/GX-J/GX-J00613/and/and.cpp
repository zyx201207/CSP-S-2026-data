#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[n-1];
		return 0;
    }
	long long ma=a[n-1];
	for(int i=2;i<=m;i++){
		ma&=a[n-i];
	}
    cout<<ma;
    return 0;	
}

