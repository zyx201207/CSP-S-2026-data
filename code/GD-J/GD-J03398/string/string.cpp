#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ax[N],ans,sum,hal;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ax[i]=a[i];
		sum+=a[i];
	}
	hal=sum/2;
	
	long long i=1,j=n,ic=0,jc=sum+1;
	while(ic<hal && jc>hal+1){
		int x,in=i,jn=j;
		if(ax[i]>ax[j]){
			x=ax[j];
			jn--;
		}else{
			x=ax[i];
			in++;
			if(ax[i]==ax[j]){
				jn--;
			}
		}
		ax[i]-=x;
		ax[j]-=x;
		
		if(c[i]!=c[j]){
			ans+=x;
		}
		
		i=in;j=jn;
		ic+=x;jc-=x;
	}
	cout<<ans;
	return 0;
}

