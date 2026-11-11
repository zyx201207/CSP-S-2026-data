#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,len,cnt,ans,x[2000001];
void find(int l,int r,int le){
	if(le==1 && x[r]-x[l]<=d) cnt++;
	else{
		for(int i=l+1;i<=r;i++){
			if(x[i]-x[l]<=d) find(i,r,le-1);
			else return ;
		}
	}
}
int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				len=0;cnt=0;
				for(int k=i;k<=j;){
					int la=x[k];
					while(x[k]-la<=d && k<=j){
						k++;
					}
					len++;
					if(k>j) break;
					else k--;
				}
				find(i,j,len);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
