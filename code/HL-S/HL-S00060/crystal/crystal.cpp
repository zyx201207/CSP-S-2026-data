#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],as[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++) {
		as[i]=a[i]-a[i-1];
		cnt=cnt+as[i]*(i-1);
		//cout<<cnt<<endl;
	}
	if(m>=cnt) {
		printf("%d",n);
		return 0;
	}
	int maxx=0,num=0,dis=0,be=0;
	dis=m,be=1,num=1;
	for(int i=2; i<=n; i++) 
	{
		if(dis-as[i]*(i-be)>=0) 
		{
			dis=dis-as[i]*(i-be);
			num++;
			maxx=max(maxx,num);
			//cout<<dis<<' '<<maxx<<' '<<be<<' '<<num<<' '<<endl;
		} 
		else 
		{
		  while(dis<as[i]*(i-be)&&num>1) dis=dis+a[i-1]-a[be],num--,be++;
		//cout<<dis<<' '<<maxx<<' '<<be<<' '<<num<<' '<<endl;
		  if(dis>=as[i])
		  {
		    dis=dis-as[i]*(i-be);
			num++;
			maxx=max(maxx,num);
		  }
		  //cout<<dis<<' '<<maxx<<' '<<be<<' '<<num<<' '<<endl;
		}
	}
	//cout<<"udfiusfhdui";
	printf("%d",maxx);
	return 0;
}