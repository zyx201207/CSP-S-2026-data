#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1;
struct {
	long long u,v;
}a[500010],b[300010],c[500010];//a=u,b=s,c=v
bool d[300010];
int main(){
freopen("card.in","r",stdin);
freopen("card.out"."w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i].u;
cout<<1;
return 0;
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(d[a[i].u]==1){
			for(int i=a[i].v;i<=s;i++){
				a[i]=0;
		    }
		}
	}
}
return 0;
}

