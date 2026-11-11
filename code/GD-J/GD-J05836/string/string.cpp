#include <bits/stdc++.h>

using namespace std;

const int N=1000086;

long long x[N];

char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n,len=0,t,tmp,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		len+=x[i];
	}
	t=len/2;
	for(long long i=1;i<=n;i++){
		if(t<=x[i]){
			tmp=i;
			break;
		}
		t-=x[i];
	}
	for(long long i=tmp+1;i<=n;i++){
		x[i+1]=x[i];
		c[i+1]=c[i];
	}
	x[tmp+1]=x[tmp]-t;
	x[tmp]=t;
	c[tmp+1]=c[tmp];
	n++;
	if(len%2==1){
		x[tmp+1]--;
	}
	long long k=0,q,p,r,i=1,j=n;//k代表左赋值右后左余下,p代表右被左赋值后右余下,q代表k的字母,r代表p的字母 
	while(i<=tmp&&j>=tmp+1){
		if(k>=x[j]){
			if(q!=c[j]){
				ans+=x[j];
			} 
			k-=x[j];
			j++;
		}else{
			while(k<x[j]){
				k+=x[i];
				if(c[i]!=c[j]){
					if(k>=x[i]){
						ans+=x[i]-k+x[j];
					}else{
						ans+=x[i];
					}
				}
				i++;
			}
			k-=x[j];
		} 
	}
	cout<<ans<<"\n";
	return 0;
}
