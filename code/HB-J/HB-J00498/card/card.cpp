#include <bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("card.in","r",stdin);
	feropen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			int f=0,f_=0;
			for(int j=i;j<=n;j++){
				if(a[j]==1) f=1;
				if(a[j]==2) f_=1;
			}
			if(f==1) x++;
			if(f_==1) y++;
		}
		cout<<x<<" "<<y;
		return 0;
	}
	return 0;
}
