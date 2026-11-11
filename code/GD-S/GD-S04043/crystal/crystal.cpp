#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N],b[N];
bool flag=true,flag1=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          											 										            	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=false;
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag1=false;
	}
	if(flag){
		cout<<m;
	}
	return 0;
}
