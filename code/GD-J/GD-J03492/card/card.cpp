#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145145],k[1145145],p[1145145],pi,ans[1145145];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	pi=1;
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		memset(k,0,sizeof(k));
		pi=0;
		for(int j=i;j<=n;j++){
			while(k[a[j]]){
				k[p[pi]]--;
				p[pi]=0;
				pi--;
			}
			pi++;
			k[a[j]]++;
			p[pi]=a[j];
		}
		for(int i=1;i<=pi;i++){
			ans[p[i]]++;
		}
		for(int i=1;i<=pi;i++){
				cout<<p[i]<<" ";
		}
		cout<<endl;
	}
//	for(int i=1;i<=n;i++){
//		int li=i,ri=n;
//		memset(k,0,sizeof(k));
//		while(li<ri){
//			for(int j=i;j<=n;j++){
//				if(a[j]==a[i])li=j;
//			}
//			for(int j=n;j>=li;j--){
//				if(a[j]==a[n])ri=j;
//			}
//	//		cout<<li<<" "<<ri<<endl;
//			if(k[li]==0)ans[a[li]]++;
//			if(k[ri]==0)ans[a[ri]]++;
//			k[li]=1;k[ri]=1;
//			li++;
//			ri--;
//		} 
//	}
//		
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

3 1
1
2 1
1
3 1
2 1
3 1
1
2 1
1
*/

