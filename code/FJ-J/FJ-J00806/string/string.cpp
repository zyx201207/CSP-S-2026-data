#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll a[N],n,l,sum1,sum2,ans;
char c[N];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	ll lt=1,rt=n,temp1=0,temp2=0;
	sum2=l;
	ll x=l/2;
	while(sum1<=x && sum2>=x && lt<rt){
//		cout<<ans<<" "<<lt<<" "<<rt<<" "<<sum1<<" "<<temp1<<" "<<sum2<<" "<<temp2<<"\n";
		if(a[lt]<=a[rt]){
			sum1+=a[lt];
			temp2+=a[rt]-a[lt];
			if(c[lt]!=c[rt]) ans+=a[lt];
			lt++;
			if(temp1>=a[lt]){
				if(sum1+a[lt]>=x){
					ans+=(sum1+a[lt]-x);
					break;
				}
				temp1-=a[lt];
				lt++;
				sum1+=a[lt];
				if(c[rt]!=c[lt]) ans+=temp1;
			}
		}else{
			sum2-=a[rt];
			temp1+=a[lt]-a[rt];
			if(c[lt]!=c[rt]) ans+=a[rt];
			rt--;
			if(temp2>=a[rt]){
				if(sum2-a[rt]<=x){
					ans+=(x-sum2+a[rt]);
					break;
				}
				temp2-=a[rt];
				rt++;
				sum2-=a[rt];
				if(c[rt]!=c[lt]) ans+=temp2;
			}
		}
	}  
//	cout<<ans<<" "<<lt<<" "<<rt<<" "<<sum1<<" "<<temp1<<" "<<sum2<<" "<<temp2<<"\n";
	cout<<ans;
	return 0;
} 
/*
0 1 3 0 0 5 0
1 1 2 0 1 4 0 
*/
