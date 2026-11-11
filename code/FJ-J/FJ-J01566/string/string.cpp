#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n,ans;
char c[N];
long long m;
struct lb{
	int x;
	char y;
}x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i]; 
		m+=a[i];
	} 
	long long m2=m/2;
	int i=0,j=0,xn=n+1;
	long long ans=0;
	while(xn--){
		ans+=a[i];
		if(ans>m2&&(ans-a[i]<m2)){
			x[j].x=m2+a[i]-ans;
			x[j].y=c[i];
			j++;
			x[j].x=ans-m2-(m%2);
			x[j].y=c[i];
			i++,j++;
		}
		else{
			x[j].x=a[i];
			x[j].y=c[i];
			i++,j++;
		}
	}
	i=0,j=j-1;
	int da=0;
	int bzd=3;
	while(i<j){
		int nb=min(x[i].x,x[j].x);
		if(x[i].y!=x[j].y){
			da+=nb;
		}
		x[i].x-=nb;
		x[j].x-=nb;
		if(!x[i].x) i++;
		if(!x[j].x) j--;
		
	}
	cout<<da;
	return 0;
} 
