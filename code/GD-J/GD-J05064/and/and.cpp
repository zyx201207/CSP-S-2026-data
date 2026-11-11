#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long maxx=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			long long shu;
			cin>>shu;
			maxx=max(maxx,shu);
		}
		cout<<maxx;		
	}
	return 0;
} 
