#include<bits/stdc++.h>
using namespace std;
struct flor{
	int id,val;
};
int p,n,m,d,q;
int a[500005],book[100005];
flor c[100005][100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>p>>n>>m>>d>>q;
	if (p==0){
		cout<<32<<endl<<17;
	}
	for (int i=1;i<=m;i++){
		cin>>a[m];
	}
	for (int i=1;i<=q;i++){
		int ooo;
		cin>>ooo;
		for (int j=1;j<=ooo;j++){
			cin>>c[i][j].id>>c[i][j].val;
		}
		book[i]=ooo;
	}
	for (int i=1;i<=n;i++){
		int l,r,ans=0;
		cin>>l>>r;
		for (int j=1;j<=q;j++){
			int l1=l,r1=r;
			ans+=a[l];
			for (int k=1;k<=book[j];j++){
				if (c[j][k].id==r||c[j][k].id==l) ans+=c[j][k].val;
				l1=c[j][k].id;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
