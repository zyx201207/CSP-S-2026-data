#include <bits/stdc++.h>
using namespace std;
long long a[50010];
bool sum[64]={0};
vector<vector<bool>> b;
vector<int> d,e;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,c=0,_max=0,s;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	b.resize(n,vector<bool>(31,0));
	sort(a,a+n);
	for(int i=0;i<n;i++){
		c=0;
		while(a[i]!=0){
			b[i][c]=a[i]%2;
			a[i]/=2;
			c++;
		}
	}
	cout<<c;
	d.resize(n);
	e.resize(n);
	for(int i=0;i<n;i++)d[i]=i;
	for(int i=c-1;i>=0;i--){
		_max=0;
		for(int j=0;j<n;j++){
			if(b[d[j]][i]==1){
				e[_max]=d[j];
				_max++;
			}
		}
		if(_max>=m){
			d.assign(_max,0);
			d=e;
			n=_max;
			sum[i]=1;
			cout<<sum[i];
		}
		else cout<<0;
	}
	return 0; 
}

