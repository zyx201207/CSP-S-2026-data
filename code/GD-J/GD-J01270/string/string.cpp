#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200100];
char c[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,z=0;
	cin>>n;
	int k=0;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		k+=a[i];
	}
	k/=2;
	int p=0,q=n,h;
	for(int i=1;i<=n;++i){
		if(p>k)break;
		if(p+a[i]<=k){
			while(q>0){
				if(a[i]-a[q]>=0){
					if(c[i]!=c[q])z+=a[q];
					a[i]-=a[q];
					a[q]=0;
					q--;
				}else{
					if(c[i]!=c[q])z+=a[i];
					a[q]-=a[i];
					a[i]=0;
					break;
				}
			}
		}else{
			h=k-i;
			while(q>0){
				if(h-a[q]>=0){
					if(c[i]!=c[q])z+=a[q];
					a[i]-=a[q];
					h-=a[q];
					a[q]=0;
					q--;
				}else{
					if(c[i]!=c[q])z+=a[i];
					a[q]-=a[i];
					a[i]=0;
					break;
				}
			}
		}
		p+=a[i];
	}
	cout<<z;
	
	return 0;
} 
