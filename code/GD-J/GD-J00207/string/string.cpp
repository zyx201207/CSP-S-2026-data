#include<bits/stdc++.h>
using namespace std;
int n,a,b[200005];
char c,d[200005];
long long len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		b[i]=a;
		d[i]=c;
		len+=a;
	}
	long long ans=0,s=0,x=n-1;
	for(int i=0;s<=len/2&&i<x;i++){
		s+=b[i];
		while(b[i]!=0){
			if(b[i]>=b[x]){
				if(d[i]!=d[x]){
					ans+=b[x];
				}
				b[i]-=b[x];
				x--;
			}
			else{
				if(d[i]!=d[x]){
					ans+=b[i]; 
				}
				b[x]-=b[i];
				b[i]=0;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
