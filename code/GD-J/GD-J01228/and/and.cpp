#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],m,maxx=-1,maxn,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxx<a[i])
			maxx=a[i],maxn=i;
	}
	b[maxn]=1;
	if(m==1)
		cout<<maxx;
	else{
		int t=-1,js;
		for(int i=1;i<=m-1;i++){
			t=-1,js=0;
			for(int j=1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<b[j]<<" "<<t<<" "<<(maxx&a[j])<<" "<<maxx<<"\n";
				if(b[j]==0){
					if(t<=(maxx&a[j]))
						b[j]=1,b[js]=0,t=maxx&a[j],js=j;
					
				}
			}
			maxx=t;
		}
	}
	cout<<maxx;
	return 0;
}
