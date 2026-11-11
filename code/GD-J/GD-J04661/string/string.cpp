#include<bits/stdc++.h>
using namespace std;
string s[200010];
long long n,a[200010],b,d=1,e,c[100],f,g,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	e=n;
	while(d<e && d>=1 && e<=n){
		f=0;
		g=0;
		if(s[d]!=s[e]){
			if(a[d]>a[e]){
				b+=a[d]-a[e];
				a[d]=a[d]-a[e];
				e--;
			}else if(a[e]>a[d]){
				b+=a[e]-a[d];				
				a[e]=a[e]-a[d];
				d++;
			}else{
				b+=a[d];
				d++;
				e--;
			}			
		}else{
			if(a[d]>a[e]){
				a[d]=a[d]-a[e];
				e--;
			}else if(a[e]>a[d]){				
				a[e]=a[e]-a[d];
				d++;
			}else{
				d++;
				e--;
			}		
		}
		while(b>0){
		    f=b%10;
			c[g]+=f;
			g++;
			b/=10;			
		}
	}
	for(int i=11;i>=0;i--){
		if(h!=0 || c[i]!=0){
			cout<<c[i];
			h=1;
		}
	}
	if(h==0)cout<<0;
	return 0;
}
