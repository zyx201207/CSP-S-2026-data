#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<=b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int N=1e6+10;
ll n,tong[N],ar[N],ls[N],num[N],m;
bool f1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	f(i,1,n){
		cin>>ar[i];
		ls[i]=num[ar[i]];
		num[ar[i]]=i;
	}
	f(i,1,n){
		f(j,1,n)f1[j]=1;
		f(j,i,n){
			if(ls[j]>=i&&f1[ls[j]]){
				for(ll k=j-1;k>=ls[j];k--){
			    	f1[k]=0;
	    		}
			}
			
		}
		f(j,i,n){
			if(f1[j])tong[ar[j]]++;
		}
	}
	f(i,1,m)cout<<tong[i]<<" ";   //67676767676767676767
	return 0;
}
