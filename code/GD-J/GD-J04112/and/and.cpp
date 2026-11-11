#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,lis[N],a[N],ans;
int main(){
	//ÁîÁîÁîÉêÉêÉêÉêÉêÌá½»Ç°½â³ýÎÄ¼þÊäÈëÊä³ö×¢ÊÍ  
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		lis[i]=a[i];
	} 
	sort(lis+1,lis+n+1);
	if(m==1){
		cout<<lis[1];
	}else if(m==2){
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				ans=max(ans,lis[i]&lis[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=lis[1];
		for(int i = 2; i <= n; i++){
			ans=ans&lis[i];
		}
		cout<<ans;
	}
	return 0;
}
