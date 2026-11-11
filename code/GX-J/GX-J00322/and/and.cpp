#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==m){
		int s;
		cin>>s;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			s=(s&x);
		}
		cout<<s;
	}else if(m==n-1){
		int a[2010];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ma=0;
		for(int i=1;i<=n;i++){
			int s,t=0;
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(t==0){
						s=a[j];
					}else{
						s=(s&a[j]);
					}
					t=1;
				}
			}
			ma=max(ma,s);
		}
		cout<<ma;
	}else if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			ma=max(ma,x);
		}
		cout<<ma;
	}
	return 0;
}
