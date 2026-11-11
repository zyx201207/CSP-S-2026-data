#include<bits/stdc++.h>
using namespace std;
struct Q{
	int a=0,id;
};
int n,d[500005],m,l,r,f[500005],s[500005],b,y,e,min1,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout); 
	cin>>n>>m;
	l=n+1;
	r=n+1;
	for(int o=1;o<=n;o++){
		cin>>d[o];
	}
	for(int o=n;o>=1;o--){
		f[d[o]]=1;
		if(f[d[o]]){int j;
			for(j=o+1;j<=n;j++){
				if(d[j]==d[o]){
					for(int k=j-1;k>o;k--){
						f[d[k]]=0;
						d[k]=0;
					}
					break;
				}
			}
		}f[d[o]]=1;
		for(int j=1;j<=m;j++){
			if(f[j]==1){
				s[j]++;//cout<<j<<' '<<f[j]<<' ';
			}
		}//cout<<'\n';
	}//cout<<'\n';
	for(int o=1;o<=m;o++){
		cout<<s[o]<<' ';
	}
	return 0;
}
