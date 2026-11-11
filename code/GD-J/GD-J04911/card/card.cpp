#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c=0,d=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			c++;
		}
		if(a[i]==2){
			d++;
		}
	}
	cout<<c<<d;
	if(m==1){
		cout<<n;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int i=2;i<=n;i++){
				if(a[i]==1&&c>1){
					c--;
				}
				else if(d>1){
					d--;
				}
					
			}
			if(c%2==1){
				b[1]++;
			}
			if(d%2==1){
				b[2]++;
			}
		}
		cout<<b[1]<<' '<<b[2];
	}
	return 0;
}

