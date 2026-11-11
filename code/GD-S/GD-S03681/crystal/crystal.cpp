#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N],ans,b[N];
signed main(){
	//ÁîÁîÁîÉêÉêÉêÉêÉêÌá½»Ç°¼ì²éÎÄ¼þ¶ÁÐ´
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];c[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i = 2; i <= n; i++){
		int tm=m;
		for(int j = i-1; j >= 1; j--){
			if(a[i]-a[j]<=tm){
				tm-=a[i]-a[j];
				c[i]++;
			}else{
				break;
			}
		}
		ans=max(ans,c[i]);
	}
	cout<<ans;
}
