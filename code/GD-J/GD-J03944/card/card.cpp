#include<bits/stdc++.h> 
using namespace std;

int a[200005],cnt[300005];
int xb[300005];
int ans[30005];
queue<int> kk,kk2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		
	}for(int kk = 1;kk<=n;kk++){
		for(int i = kk;i<=n;i++){
			if(cnt[a[i]]!=0){
				for(int j = xb[a[i]];j<=i;j++ ){
					cnt[j] = 0;
					
				} 
				xb[a[i]] = i;
				cnt[a[i]]++;
				
				
				
			}else {
				cnt[a[i]]++;
				xb[a[i]] = i;
				//cout<<xb[1]<<' '<<xb[2]<<' '<<xb[3]<<' '<<endl;
			}
		}
		for(int j = 1;j<=m;j++){
			if(cnt[j]!=0){
				ans[j]++; 
				cnt[j] = 0;
			}//cout<<ans[j]<<' ';
		}//cout<<endl;
	}for(int i = 1;i<=m;i++){
		cout<<ans[i]<<' ';
		
	} 
	
	

}
