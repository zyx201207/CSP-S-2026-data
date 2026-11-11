#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],b[200005];
char c[200005],d[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
		d[i]=c[n-i+1];
	}
	int is=1,in=1,js=1,jn=1;
	while(true){
		int al=a[is]-in+1,bl=b[js]-jn+1;
		if(c[is]==d[js]){
			if(al<bl){
				is++,in=1;
				jn+=al;
			}
			else if(al>bl){
				js++,jn=1;
				in+=bl;
			}
			else{
				is++,js++;
				in=jn=1;
			}
		}
		else{
			if(al<bl){
				is++,in=1;
				jn+=al;
				ans+=al;
			}
			else if(al>bl){
				js++,jn=1;
				in+=bl;
				ans+=bl;
			}
			else{
				is++,js++;
				in=jn=1;
				ans+=al;//al==bl
			}
		}
		
		if(is==n+1 && js==n+1 && in==1 && jn==1)break;
	}
	ans/=2;
	cout<<ans;
	return 0;
} 
