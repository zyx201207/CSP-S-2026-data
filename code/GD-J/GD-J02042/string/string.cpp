#include<iostream>
using namespace std;
int n;
int a[200010];
char c[200010];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l1=1,l2=a[n],r1=a[1],r2=n,le1=a[1],le2=a[n],x=1,y=n;
	while(x<y){
		if(le1>le2){
			if(c[x]!=c[y]){
				ans+=le2;
			}
			le1-=le2;
			l1+=le2;
			y--;
			r2=l2-1;
			l2-=a[y];
			le2=r2-l2+1;
		}
		else if(le2>le1){
			if(c[x]!=c[y]){
				ans+=le1;
			}
			le2-=le1;
			r2-=le1;
			x++;
			l1=r1+1;
			r1+=a[x];
			le1=r1-l1+1;
		}
		else{
			if(c[x]!=c[y]){
				ans+=le1;
			}
			le1-=le2;
			l1+=le2;
			y--;
			r2=l2-1;
			l2-=a[y];
			le2=r2-l2+1;
			le2-=le1;
			r2-=le1;
			x++;
			l1=r1+1;
			r1+=a[x];
			le1=r1-l1+1;
		}
	}
	cout<<ans;
	return 0;
}
