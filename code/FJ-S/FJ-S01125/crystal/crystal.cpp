#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=a[1],r=a[i];
		if(r-l>m){
			r--;
		}
		else if(r-l<m){
			m-(r-l);
			l++;
			cnt++;
		}
		else if(m==0){
			break;
		}
	}
	cout<<cnt;
	return 0;
}
