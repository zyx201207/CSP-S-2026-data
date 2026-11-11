#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,lft,rght,ans,cnt,ccnt;
long long x[5020],l[5020],r[5020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			lft=i;rght=i;
			lft=lower_bound(x+1,x+i-1,x[i]-d)-x;
			rght=upper_bound(x+i+1,x+n,x[i]+d)-x-1;
			while(lft>=1&&x[i]-x[lft]<=d)lft--;
			while(rght<=n&&x[rght]-x[i]<=d)rght++;
			l[i]=lft+1;r[i]=rght-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				if(r[i]-l[i]>1)break;
				if(r[i]-l[j]==1){
					cnt=1;ccnt=1;
					while(i-cnt>=1&&l[i-cnt]==i-cnt-1)cnt++;
					while(j+ccnt<=n&&r[j+ccnt]==j+ccnt+1)ccnt++;
					ans+=cnt*ccnt;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
0 4
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

1
2
0
1
*/
