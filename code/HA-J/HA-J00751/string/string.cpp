#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
		cin>>c[i];
	}
	int l=1,r=n,ans=0;
	int last_l=0,last_r=0;
	char res_l,res_r;
	while(l<=r){
		if(last_l){
			if(res_l==c[r]){
				if(last_l<=a[r]){
					a[r]-=last_l; last_l=0; l++; 
				}
				else{
					last_l-=a[r]; r--; 
				}
			}
			else{
				if(last_l<=a[r]){
					ans+=last_l;
					a[r]-=last_l; last_l=0; l++;
				}
				else{
					ans+=a[r];
					last_l-=a[r]; r--; 
				}
			}
		}
		else if(last_r){
			if(res_r==c[l]){
				if(last_r<=a[l]){
					a[l]-=last_r; last_r=0; r--;  
				}
				else{
					last_r-=a[l]; l++; 
				}
			}
			else{
				if(last_r<=a[l]){
					ans+=last_r;
					a[l]-=last_r; last_r=0; r--; 
				}
				else{
					ans+=a[l];
					last_r-=a[l]; l++; 
				}
			}
		}
		else if(c[l]==c[r]){
			if(a[l]>a[r]){
				last_l=a[l]-a[r];
				res_l=c[l];
				r--;
			}
			else if(a[l]==a[r]){
				l++,r--;
			}
			else{
				last_r=a[r]-a[l];
				res_r=c[r];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				last_l=a[l]-a[r];
				res_l=c[l];
				ans+=a[r]; r--; 
			}
			else if(a[l]==a[r]){
				ans+=a[l]; l++,r--; 
			}
			else{
				last_r=a[r]-a[l];
				res_r=c[r];
				ans+=a[l]; l++; 
			}
		}
	}
	cout<<ans;
	return 0;
}

