#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1001001];
long long k,o[1001001],a[5010][5010],t[5010][5010],a1[5010][5010],t1[5010][5010];
long long x,y,h,v;
long long sum£¬ans;
long long bo=0;
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>o[j];
			if(j%2!=0)a[i][j/2+1]+=o[j];
			else t[i][j/2]+=o[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int z=1;z<=q;z++){
		h=x;
		sum=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=2*k;j++){
				if(h==y+1)bo=1;
				if(bo==0){
					if(a[i][j]==h&&ans<=d){
						h++;
						sum+=t[i][j];
						v=a[i][j];
						ans++;
					}else{
						h=v;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
