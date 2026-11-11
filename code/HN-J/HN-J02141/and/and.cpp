#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma,ma1,ma2;  
bool f,f1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    	cin>>a[i];
    	if(a[i]==a[i-1]){
    		ma=max(ma,a[i]);
    		f=1;
		}
		if((a[i]+1)%2==0){
			ma2=max(ma2,a[i]);
			f1=1;
		}
		ma1=max(ma1,a[i]);
	}
	if(f){
		cout<<ma;
		return 0;
	}
	if(f1){
		cout<<ma2;
		return 0;
	}
	cout<<ma1;
    return 0;
}
