#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t[10];
struct line{
	int a[500005];
}l[3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>t[i];
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int g,f;
			cin>>g>>f;
			l[i].a[g]=f;
		}
	}
	int g,h;
	for(int i=1;i<=q;i++){
		int time=0;
		cin>>g>>h;
		cout<<"time:"<<time<<endl;
		time+=(l[i].a[h]);
		time+=(l[i].a[g]);
		time+=t[g];
		time+=t[h];
		cout<<time<<endl;
	}
	return 0;
}
