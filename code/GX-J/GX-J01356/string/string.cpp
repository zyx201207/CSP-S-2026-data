#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int n,l=1,r,atl=1,atr;
int a[N],at[N];
char c[N];
int ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
		at[i]=r;
	}
	
	atr=n;
    while(atl<atr){
		l+=a[atl];
		
		int num=a[atl];
		while(num>0){
			int sum=r-at[atr-1];
			sum=min(sum,num);
			if(c[atr]!=c[atl])ans+=sum;
			r=r-sum;
			num-=sum;
			
			if(r==at[atr-1]){
				atr--;
			}
			if(r<=l)break;
		}
		
		atl++;
	}
	
	cout<<ans;
    return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
