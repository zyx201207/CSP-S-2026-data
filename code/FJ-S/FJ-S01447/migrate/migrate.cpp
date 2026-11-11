#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<15;
long long n,tili,a[MAXN],st[MAXN]={0,1},lujing=1,c,d,num;
int main (){
	freopen("migrate.in","r",stdin);
	freopoen("migrate.out","w",stdout);
	cin>>c>>d;
	for(int i=1;i<=d;i++){
		lujing=0;
		cin>>n>>tili;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=abs(a[1])+abs(a[n]);i++){
			st[i]=i;
		}
		for(int i=2;i<=abs(a[1])+abs(a[n]);i++){
			if(st[i]%tili==1) lujing++;
			st[i]=lujing;
		}
		for(int i=1;i<=n;i++) if(st[a[i]+1]==2) num++;
		cout<<num;
		num=0;
	}
	return 0;
}
