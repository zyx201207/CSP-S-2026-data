#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n-1);
	int cnt=1,q,maxcnt=0;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
			q=a[i];
		}
		maxcnt=max(cnt,maxcnt);
	}
//	maxcnt++;
	for(int i=0;i<n;i++){
		if(a[i]==q)
		{
			int x=i-maxcnt,y=i+1;
			while(m){
				if(x>=0){
					if(m<a[i]-a[x])break;
					m-=a[i]-a[x];
					a[x]=a[i];
					x--;
					maxcnt++;
				}
				else{
					if(m<(a[y]-a[i])*(i-1))break;
					m-=(a[y]-a[i])*(i-1);
					a[y]=a[i];
					y++;
					maxcnt++;
				}
			}
		}
	}
	cout<<++maxcnt;
	return 0;
}
