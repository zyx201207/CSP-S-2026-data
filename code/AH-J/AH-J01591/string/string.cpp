#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
char c[N];
int a[N];
struct node{
	int z;
	char f;
}b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=-1,nn,ans=0,ak=0;
	cin>>nn;
	for(int i=1;i<=nn;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			ak+=a[i];
		}
		else{
			n++;
			b[n]={ak,c[i-1]};
			ak=a[i];
		}
	} 
	n++;
	b[n]={ak,c[nn]};
	int l=1,r=n;
	while(l<=r){
		if(b[l].f==b[r].f){
			if(b[l].z<b[r].z){
				b[r].z-=b[l].z;
				l++;
			}
			else if(b[l].z==b[r].z){
				l++,r--;
			}
			else{
				b[l].z-=b[r].z;
				r--;
			}
		}
		else{
			if(b[l].z<b[r].z){
				ans+=b[l].z;
				b[r].z-=b[l].z;
				l++;
			}
			else if(b[l].z==b[r].z){
				ans+=b[l].z;
				l++,r--;
			}
			else{
				ans+=b[r].z;
				b[l].z-=b[r].z;
				r--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
