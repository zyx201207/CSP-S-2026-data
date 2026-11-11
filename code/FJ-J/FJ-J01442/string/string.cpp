#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n,z=0,x,y,cnt=0,top,ans1=0,ans2=0,ans=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		z+=a[i];
		cin>>c[i];
	}
	top=n;
	y=a[top];
	for(i=1;i<=n;i++){
		x=a[i];
		cnt+=x;
		while(x){
			if(c[i]==c[top]){
				if(x<y){
					y-=x;
					x=0;
				}else{
					x-=y;
					top--;
					y=a[top];
				}
			}else{
				if(x<y){
					y-=x;
					ans+=x;
					x=0;
				}else{
					x-=y;
					ans+=y;
					top--;
					y=a[top];
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}