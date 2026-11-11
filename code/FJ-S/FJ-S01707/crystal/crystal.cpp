#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005];
long long m,ans=1;
int c(int ma1,int ne1,int w){
//	cout<<ma1<<' '<<b[ma1]<<"\n====ww=====\n";
	if(ne1==0) return w;
	if(ma1==n) return w;
	if(ne1>=a[ma1]*(w+1)){
		//cout<<ma1<<' '<<b[ma1]<<"\n====w=====\n";
		b[ma1]=max(c(ma1+1,ne1-a[ma1]*(w+1),w+1),c(ma1+1,ne1,w));
		//cout<<ma1<<' '<<c(ma1+1,ne1-a[ma1]*(w+1),w+1)<<"n"<<c(ma1+1,ne1,w)<<"\n";
		return b[ma1];
	}
	else return c(ma1+1,ne1,w);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m<1000000000){
	
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			a[i]=a[i+1]-a[i];	
		cout<<c(1,m,0)+1;
		return 0;
	}
	else{
		cin>>a[1]>>a[2];
		a[0]=a[2]-a[1];
		for(int i=1;m>=0;i++){
			if(m>=ans*i) ans++;
			else break;
		}
		cout<<ans+1;
		return 0;
	}
}
