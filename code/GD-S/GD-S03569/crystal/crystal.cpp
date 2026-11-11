#include<bits/stdc++.h>
#define ll long long
int n,m,b[500005],ans=0;
ll a[500005],c[500005],lma=LONG_LONG_MIN,lmi=LONG_LONG_MAX;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f; 
}
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	int gap=0;
	bool check=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==2) gap=a[i]-a[i-1];
		else if(i>2){
			if(a[i]-a[i-1]!=gap) check=0;
		}
		if(a[i]>lma) lma=a[i];
		if(a[i]<lmi) lmi=a[i];
	}
//	cout<<lma<<' '<<lmi<<"+++++++\n";
	if(check){
		for(int i=1;i<=n-1;i++){
			if(m>=i*gap){
				m-=i*gap;
				ans++;
			}
			else break;
		}
		cout<<ans+1<<'\n';
		return 0;
	}
	if(lma<=100&&lmi>=-100){
		lma-=lmi;
//		cout<<lma<<' '<<lmi<<"======\n";
		for(int i=1;i<=n;i++){
			b[int(a[i])-lmi]++;
		}
//		cout<<b[0]<<'\n';
		int flag=m,j,an,x;
		for(int i=1;i<=lma+m;i++){
			flag=m;j=i-1;an=b[i];
//			cout<<b[i]<<'\n';
			while(flag>0&&j>=0){
				if(flag>=(i-j)*b[j]){
					an+=b[j];
					flag-=(i-j)*b[j];
				}
				else{
					x=floor(flag/(i-j));
					an+=x;
					flag=0;
				}
				j--;
			}
			ans=max(an,ans);
//			cout<<an<<'\n';
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
/*
5 5
1 2 4 8 9
*/
}
