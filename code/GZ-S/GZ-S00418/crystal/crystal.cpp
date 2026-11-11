//GZ-S00418 都匀一中 潘洪创  
#include<bits/stdc++.h>
using namespace std;
#define maxn 5050
long long n,m,a[5050];
long long c[maxn]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
    cin>>n>>m;
    if(n>5000){
    	int x,y;
    	cin>>x,y;
    	if(x==1){
	    	int sum=0,ans=0,ma;
    		for(int i=1;i<=n;i++){
    			sum+=i;
    			if(sum==m){
    				ans=i+1;
    				cout<<ans;
    				return 0;
				}
				if(sum>m){
					ans=i;
    				cout<<ans;
    				return 0;
				}
			}
		}
		else{
			int sum=0,ans=0,ma,d;
			d=y-x;
    		for(int i=x;i<=n;i++){
    			sum+=d*i;
    			if(sum==m){
    				ans=i+1;
    				cout<<ans;
    				return 0;
				}
				if(sum>m){
					ans=i;
    				cout<<ans;
    				return 0;
				}
			}
		}
	}
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //scanf("%d",&a[i]);
        //cout<<a[i];
	}
    sort(a+1,a+n+1);
    //cout<<"done"<<'\n';
    for(int i=1;i<=n;i++){
    	c[i]=a[i]-a[i-1];
	}
	//cout<<"\n";
    //cout<<"done"<<'\n';
    //for(int i=1;i<=n;i++)
    //cout<<a[i];
    //for(int i=1;i<=n;i++){
    //	int sum=0;
    //	for(int j=i+1;i<=n;j++){
    //		b[i][j]=fabs(a[i]-a[j]);
	//	}
	//}
	int ma=0;
	for(int i=1;i<=n;i++){
		int ans=1,sum=0;
		for(int j=i-1;j>-1;j--){
			if(j==0){
				ans=i-j;
				//cout<<ans;
				break;
			}
			for(int k=i;k>j;k--)
				sum+=c[k];
			if(sum>m){
				ans=i-j;
				//cout<<ans;
				break;
			}
			if(sum==m){
				ans=i-j+1;
				//cout<<ans;
				break;
			}
		}
		ma=max(ans,ma);
	}
	//for(int i=1;i<=n;i++)
	//	cout<<f[i]; 
	cout<<ma;
	int hi;
	//cin>>hi;
	//cout<<hi;
	return 0;
}




