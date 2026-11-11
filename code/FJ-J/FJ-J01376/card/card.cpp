#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l001[555555],l009[333333],l003[555555];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,he,ta;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&l001[i]);
	}
	for(int ti=1;ti<=n;ti++){
		memset(l003,0,sizeof(l003));
		he=1;ta=1;
		for(int i=ti;i<=n;i++){
			for(int a=he;a<ta;a++){
				if(l003[a]==l001[i]){
					ta=a;
				}
			}
			l003[ta++]=l001[i];
		}
		for(int i=he;i<ta;i++){
			l009[l003[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<l009[i]<<' ';
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

