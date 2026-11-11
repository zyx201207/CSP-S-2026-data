#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],dm,pos,pos2,maxn=-1,sum,sum2;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		while(m>0){
			m-=a[++pos];
		}
		pos++;
		if(m<0)cout<<pos-1<<endl;
		else cout<<pos<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dm=m;
	    bool flag=true;
		for(int j=1;j<=i;j++){
			if(dm-(a[i]-a[j])>=0)dm-=(a[i]-a[j]);
			else{
				flag=false;
				break;
			}
		}
		if(flag)maxn=max(maxn,(long long)i);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dm=m;
	    bool flag=true;
		for(int j=1;j<=i;j++){
			if(dm-(a[1]-a[j])>=0)dm-=(a[1]-a[j]);
			else{
				flag=false;
				break;
			}
		}
		if(flag)maxn=max(maxn,(long long)i);
	}
	cout<<maxn;        
	return 0;
}/*
5 5
1 2 3 4 5
0
*/
