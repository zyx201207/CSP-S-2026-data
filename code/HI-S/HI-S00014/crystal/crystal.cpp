#include<bits/stdc++.h>
using namespace std;
long long sj[500050],m,pjs=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	sort(sj+1,sj+n+1);
	pjs=sj[1];
	for(int i=2;i<=n;i++){
		if(m<0){
			break;
		}
		x++;
		m-=(i-1)*(sj[i]-pjs);
		pjs=sj[i];
	}
	cout<<x;
	return 0;
} 
