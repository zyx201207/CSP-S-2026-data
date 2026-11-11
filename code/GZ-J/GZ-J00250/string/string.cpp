//GZ-J00250 贵阳市新世界学校 李宗运 
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],n,cnt,l,r,p;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1,r=n;
	while(r>l){
		p=1;
		if(c[l]==c[r])p=0;
		if(a[l]>a[r]){
			cnt+=(p*a[r]);
			a[l]-=a[r];
			a[r]=0;
			r-=1;
		}
		else if(a[l]==a[r]){
			cnt+=(p*a[l]);
			a[l]=0,a[r]=0;
			r-=1,l+=1;
		}
		else{
			cnt+=(p*a[l]);
			a[r]-=a[l];
			a[l]=0;
			l+=1;
		}
	}
	cout<<cnt;
	return 0;
	
} 
