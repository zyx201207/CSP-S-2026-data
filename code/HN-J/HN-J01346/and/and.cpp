#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,t,y=1,pos1,pos2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if (m==1){
		cout<<maxx;
		return 0;
	}
	if (m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
		return 0;
	}
	if (m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
		return 0;
	}
	maxx=0;
	while(y!=m){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t=a[i]&a[j];
				if (maxx<t){
					maxx=t;
					pos1=i;
					pos2=j;
				}
			}
		}
		y++;
		a[pos1]=maxx;
		a[pos2]=1;
		maxx=0;
	}
	cout<<a[pos1];
	return 0;
} 
