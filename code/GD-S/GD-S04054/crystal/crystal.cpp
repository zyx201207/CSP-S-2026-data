#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=0x3f3f3f3f;
int n,m,a[N],ans,lst;
bool tp1,tp2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			lst=a[2]-a[1];
			tp1=1;
			if(a[2]-a[1]==1)tp2=1;	
		}
		if(i>2){
			if(a[i]-a[i-1]!=lst)tp1=0,tp2=0;
		}
	}
	if(tp2){
		int i;
		for(i=1;m>0;i++){
			m-=i;
		}cout<<i;
		return 0;
	}if(tp1){
		int i,j;
		for(i=lst,j=0;m>0;i+=lst,j++){
			m-=i;
			//cout<<m<<' '<<i<<' '<<j<<endl;
		}cout<<j;
		return 0;
	}
	sort(a+1,a+1+n);
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}*/
	for(int i=1;i<=n;i++){
		int k=m,sum=0;
		for(int j=i;j>=1;j--){
			int d=a[i]-a[j];
			k-=d;
			if(k<0)break;
			sum++;
		}ans=max(ans,sum);
	}cout<<ans;
	return 0;
}/*

5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
