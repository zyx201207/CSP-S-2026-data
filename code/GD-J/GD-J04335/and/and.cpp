#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	
	int n,m,ans=0;
	cin >> n >> m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			string x1,y1,x2,y2;
			int x=a[i],y=a[j],max_n=0;
			while(x>0){
				if(x%2==0){
					x2+="0";
					x/=2;
				}else{
					x2+="1";
					x/=2;
				}
			}
			
			while(y>0){
				if(y%2==0){
					y2+="0";
					y/=2;
				}else{
					y2+="1";
					y/=2;
				}
			}
			
			int len=max(x2.size(),y2.size());
			for(int k=0;k<=len;k++){
				if(x2[k]=='1'&&y2[k]=='1'){
					int en=1;
					for(int l=1;l<=k;l++) en*=2;
					max_n+=en;
				}
			}
			if(max_n>ans)
				ans = max_n;
		}
	}
	cout << ans;
	return 0;
}
 
