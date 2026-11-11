//GZ-J00523 зѓгІКщ КывужабЇ 
#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	long long n,m;
	cin>>n>>m;
	long long k=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i+1]){
			k--;
			cout<<k+1<<" ";
		}
		
	}
	return 0;
} 

