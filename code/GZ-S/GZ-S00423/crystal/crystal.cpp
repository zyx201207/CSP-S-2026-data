//GZ-S00423 ¿ÓΩ®¿§ 
#include <bits/stdc++.h>
using namespace std;
const int N=11454;
#define ll long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll k,l,a[N]={0},end=0;
	cin>>k>>l;
	for (int i=1;i<=k;i++){
		cin>>a[i];
	}
	sort(a,a+k);
	for (int i=k;i>0;i--){
		ll j=l;
		int c=i,b=0;
		while (j>0&&c!=1){
			j=j-(a[i]-a[c-1]);
			if (j>=0){
				b++;
			}
			c--;
		}
		if(end<b){
			end=b;
		}
	}
	cout<<end+1<<endl;
	return 0;
} 
//K=L
 

