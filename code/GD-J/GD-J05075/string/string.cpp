#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[400020],s=0,cnt=0;
char c[200010];
void check(){
	int l=0,r=s-1;
	while(l<=r){
		int ll=lower_bound(b,b+n*2,l)-b,rr=lower_bound(b,b+2*n,r)-b;
		if(ll%2==0) ll=ll/2+1;
		else ll=(ll+1)/2;
		if(rr%2==0) rr=rr/2+1;
		else rr=(rr+1)/2;
		if(c[ll]!=c[rr]) cnt+=1;
		l+=1,r-=1;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		if(i==1) b[0]=0,b[1]=a[i]-1;
		else b[2*i-2]=b[2*i-3]+1,b[2*i-1]=b[2*i-2]+a[i]-1;
	}
	check();
	cout<<cnt<<endl;
	return 0;
}
