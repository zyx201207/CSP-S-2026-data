#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int ans;
int a[200005];
bool cmp(int xx,int yy){
	return xx>yy;
}
void dafashi(int x,int sum){
	if(num==m){
		ans=max(ans,sum);
		return ;
	}
	if(x==n+1) return ;
	num++;
	int t;
	if(num==1) t=a[x];
	else t=sum&a[x];
	dafashi(x+1,t);
	num--;
	dafashi(x+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2000){
		if(m==n){
			int t=a[1];
			for(int i=2;i<=n;i++) t&=a[i];
			cout<<t;
		}
		else{
			dafashi(1,0);
			cout<<ans;
		}
	}
	else{
		sort(a+1,a+n+1,cmp);
		if(a[1]<4){
			ans=3;
			for(int i=1;i<=n;i++){
				m--;
				if(a[i]!=a[i-1]&&i!=1)
					if(a[i]==2) ans=2;
					else ans=1;
				if(m==0)
					break;
			}
			cout<<ans;
		}
		else{
			cout<<a[1];	
		}
	}
	return 0;
}
