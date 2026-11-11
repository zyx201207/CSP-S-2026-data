#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500010],num;
vector<int>e[510];
vector<int>t[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			int x,y;
			cin>>x>>y;
			e[i].push_back(x);
			t[i].push_back(y);
		}
	}
	num=t[1][1];
	if(n==1){
		for(int i=1;i<=q;i++){
			int sx,ex,sum;
			cin>>sx>>ex;
			sum=a[sx]+a[ex];
			for(int j=0;j<e[1].size();j++){
				if(e[1][j]==sx){
					sum+=t[1][j];
					break;
				}
			}
			for(int j=0;j<e[1].size();j++){
				if(e[1][j]==ex){
					sum+=t[1][j];
					break;
				}
			}
			cout<<sum<<"\n";
		}
		return 0;
	}else if(n==2){
		for(int i=1;i<=q;i++){
			int sx,ex,sum,num1=0,num2=0;
			cin>>sx>>ex;
			sum=a[sx]+a[ex];
			for(auto y:e[1]){
				if(y==sx) num1=1;
				if(y==ex) num2=1;
			}
			if(num1==1 && num2==1){
				for(int j=0;j<e[1].size();j++){
					if(e[1][j]==sx){
						sum+=t[1][j];
						break;
					}
				}
				for(int j=0;j<e[1].size();j++){
					if(e[1][j]==ex){
						sum+=t[1][j];
						break;
					}
				}
			}
			num1=0,num2=0;
			for(auto y:e[2]){
				if(y==sx) num1=1;
				if(y==ex) num2=1;
			}
			if(num1==1 && num2==1){
				for(int j=0;j<e[2].size();j++){
					if(e[1][j]==sx){
						sum+=t[2][j];
						break;
					}
				}
				for(int j=0;j<e[2].size();j++){
					if(e[1][j]==ex){
						sum+=t[2][j];
						break;
					}
				}
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}
