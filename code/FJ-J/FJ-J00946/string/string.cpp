#include<bits/stdc++.h>
using namespace std;
long long a[200005],c[200005],st[200005],ed[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		char s;
		st[i]=sum+1;
		cin>>a[i]>>s;
		c[i]=s-'a'+1;
		sum+=a[i];
		ed[i]=sum;
//		cout<<st[i]<<" "<<a[i]<<" "<<ed[i]<<" "<<c[i]<<endl;
	}
	long long ans=0;
	long long r=sum,l=1,x=1,y=n;
	while(x<y){
		long long js=min(ed[x]-l+1,r-st[y]+1);
		int flx=0,fly=0;
		if(js==ed[x]-l+1) flx++;
		if(js==r-st[y]+1) fly--;
	//	cout<<ed[x]-l+1<<" "<<r-st[y]+1<<endl;
		l+=js;
		r-=js;
//		cout<<l<<" "<<r<<js<<endl;
		if(c[x]!=c[y]) ans+=js;
		x+=flx;
		y+=fly;
	}
	cout<<ans;
	return 0;
}
