#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM=5010;
int n,m,a[MAXM],x,dif[20][20];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	if(n<=5000){
		int ans1=-2e9;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dif[i][j]=abs(a[i]-a[j]);
		}
		for(int i=1;i<=n;i++){
			int anst=0,cz=m;
			for(int j=1;j<=n;j++){
				int tmp=2e9,p;
				for(int k=1;k<=n;k++){
					if(dif[i][k]<=tmp)p=k;
					tmp=min(tmp,dif[i][k]);
				}
				if(cz>=tmp){
					cz-=tmp;
					dif[i][p]=2e9;
					anst++;
				}
			}
			ans1=max(ans1,anst);
		} 	
		cout<<ans1;
	}else{
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		x=a[2]-a[1]; 
		int cnt=1;
		while(m>0&&cnt<n-1){
			m-=((cnt-1)/2+1)*x;
			if(m>=0)cnt++;
		}
		cout<<cnt;	
	}
	return 0;
} 
//Û@¿·¿·àOï¾ï¾gßWþ‹ï¾ÚpgßWþ‹û|ß~öÆXï¾ÆXëŸÄÌgßWþ‹û|ß~ögßWþ‹û|ß~ö ïû üK‡JÀòà¹úŽ X·­‘¶¶OÝÂÂñ•[µè·­‘¶¶OÝÂÂñ•[µè AâŠ¼L»ü˜m­üoµM—îÑð
