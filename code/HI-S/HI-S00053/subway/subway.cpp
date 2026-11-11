#include <bits/stdc++.h>
using namespace std;
struct o{
	int x,y,k,l;
}b[500005];
bool cmp(o a,o b){
	return a.y<b.y;
}
bool p(o a,o b){
	return a.l<b.l;
}
long long c,n,m,d,q,a[500005],w;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int g,h;
		cin>>w;
		if(w==1)cin>>g>>h;
		else cin>>b[i].x>>b[i].y>>b[i].k>>b[i].l;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int s=a[x];
		int f=s;
		if(x<y){
			sort(b+1,b+1+n,cmp);
			while(x<y){
				s+=a[x];
				for(int i=1;i<=n;i++){
					if(b[i].x==x&&b[i].k==y)f+=b[i].x;
					else if(b[i].x==y&&b[i].k==x)f+=b[i].k;
					if(b[i].x==i){
						s+=b[i].y;
						x++;
					}
				}
			}
			cout<<max(f,s)<<endl;
		}
		else{
			sort(b+1,b+1+n,p);
			while(x>y){
				s+=a[x];
				for(int j=n;j>=1;j--){
					if(b[i].x==x&&b[i].k==y )f+=b[i].k;
					else if(b[i].x==y&&b[i].k==x)f+=b[i].x;
					if(b[i].l==j){
						s+=b[i].l;
						x--;
					}
				}
			}
			cout<<max(f,s)<<endl;
		}
	}
	return 0;
}  

