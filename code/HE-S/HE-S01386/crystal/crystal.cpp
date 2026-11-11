#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,a[1000000000],b=0,sum=1;
	int beifen=m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    b=a[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;i<n;j++){
        	if(m<=0){
        		break;
			}
        	m-=(a[n-i]-a[j]);
        	sum++;
		}
	}
	cout<<sum+1;
	return 0;
}
