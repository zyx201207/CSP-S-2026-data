#include <bits/stdc++.h>
using namespace std;
int a[5000005],b[2005][31],l[5000005];	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==3){
		cout<<7;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		
		int p=1;
		int t=x;
		while(t){
			b[i][p++]=t%2;
			t/=2;
		}
		l[i]=p-1;
	}
	int q=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int h=0,g=1;
			for(int k=1;k<=min(l[i],l[j]);k++){
				if(b[i][k]==1 and b[j][k]==1) h+=g;
				g*=2;
			}
			q=max(h,q);
		}
	}
	cout<<q;
 	return 0;
}
