#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],ans=0,k[3],z[4000],x=0,y=0,o=0,p=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o=a[1];
		if(a[i]!=k[1]){
			p=a[i];
		}
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(i%2!=0){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				k[i]++;
			}
			if(k[o]%2==1) x++;
			if(k[p]%2==1) y++;
		}
		cout<<x<<' '<<y;
	}
	return 0;
}
