#include<bits/stdc++.h>
#define fayuge cout<<ans
#define int long long
using namespace std;
int n;
char c[200100];
int a[200100];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>a[x]>>c[x];
	}
	int p1=1,p2=n;
	while(p1<=p2){
		if(c[p1]==c[p2]){
			int t=a[p1]-a[p2];
			if(t>0)a[p1]=t,a[p2]=0,p2--;
			else if(t==0)a[p1]=a[p2]=0,p1++,p2--;
			else a[p1]=0,a[p2]=-t,p1++;
		}
		else{
			if(a[p1]<a[p2]){
				a[p2]-=a[p1];
				ans += a[p1];
				a[p1]=0;
				p1++;
			}
			else if(a[p1]==a[p2]){
				ans+=a[p1];
				a[p1]=a[p2]=0;
				p1++,p2--;
			} 
			else{
				a[p1]-=a[p2];
				ans += a[p2];
				a[p2]=0;
				p2--; 
			}
		}
	}
	fayuge;
	return 0;
}
