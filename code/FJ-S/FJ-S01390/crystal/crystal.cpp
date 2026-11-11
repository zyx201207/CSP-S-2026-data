#include<bits/stdc++.h> 
using namespace std;
int n,m;
int cnt=0,sum=0;
int a[1000000];			
int main(){
	freeopen("crystal.in","r",stdin);
    freeopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
			cnt+=a[i]-a[i-1];
			sum+=2;
			if(cnt==m) cout<<sum;
			else  continue;
	}
	return 0;
}
