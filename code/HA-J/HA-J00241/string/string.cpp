#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long i=1,j=n;
	long long x=1,y=a[j];
	while(1){
		if(((i==j)&&(x>=y))||(i>j))break;
		if(i==j){
			break;
		}
		sum=min(a[i]-x+1,y);
		x+=sum;
		y-=sum;
		if(c[i]!=c[j])ans+=sum;
		if(x>a[i]){
			i++,x=1;
		}
		if(y<1){
			j--,y=a[j];
		}
	}
	cout<<ans;
	return 0;
}
