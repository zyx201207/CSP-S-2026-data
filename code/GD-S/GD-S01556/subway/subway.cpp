#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k[500005],x,y;
long long a[500005],asd[5005][5005],qwe[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>asd[i][j]>>qwe[i][j];
		}
	}
	long long s,now;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		now=x;
		s=0;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k[j];o++){
				if(asd[j][o]==now){
					now=asd[j][o+1];
					s+=qwe[j][o];
				}
			}
		}
		s+=a[x];
		s+=a[now];
		cout<<s<<endl;
	}
	
	return 0;
}
