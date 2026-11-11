#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[500000];
int m;
int p;
int num;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n,cmp);
	p=a[1];
	for(int i=1;i<=m;i++){
		num=0;
		int o=1;
		while(a[i]){
			if(p%2==1&&a[i]%2==1){
				num+=o;
			}o*=2;
			a[i]=a[i]>>1;
		}p=num;
	}cout<<p;
	return 0;
}


