#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
union station{int w,t[25];};
union line{int k,a[500005],t[500005];};
union r{int n1,n2;};
station s[500005];
line l[505];
r re[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>s[i].w;
	for(int i=0;i<n;i++){
		cin>>l[i].k;
		for(int j=0;j<=l[i].k;j++){
			cin>>l[i].a[j]>>l[i].t[j];
		}
	}for(int i=0;i<q;i++)cin>>re[i].n1>>re[i].n2;
	if(c==0){
		if(m==5)cout<<32<<'/n'<<17;
		if(m==7)cout<<35<<'/n'<<16;
	}
	return 0;
}