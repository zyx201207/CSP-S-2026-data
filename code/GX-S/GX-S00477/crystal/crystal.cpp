#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n,cnt=0;
ll m,a[N],c[N];
inline ll rd(){
	char c=getchar();
	ll k=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=k*10+c-'0';c=getchar();}
	return k*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();m=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int c=0,tmp=0;
		for(int j=i;j>=0;j--){
			if(tmp+a[i]-a[j]<=m){
				tmp+=a[i]-a[j];
				c++;
			}	
		}
		cnt=max(cnt,c);
	}
	cout<<cnt<<'\n';
	return 0;
}
