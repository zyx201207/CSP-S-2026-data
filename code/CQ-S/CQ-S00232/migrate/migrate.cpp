#include<bits/stdc++.h>
using namespace std;
#define int long long
int test,t;
void solve(){
	int n,d;
	cin>>n>>d;
	vector<int>a(n+1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int len=1;len<=n;len++){
		for(int start=1;start+len-1<=n;start++){
			int l=start,r=start;
			int cnt=0;
			int f=start;
			while(l<=r&&r<=start+len-1){
				if(a[r]-a[l]>d){
					l=r;
					cnt++;
					if(cnt==1)f=r-1;
					if(r==start+len-1)cnt++;
				}else {
					r++;
				}
			}
			
			l=start,r=start;
			int cntt=0;
			int ff=0;
			int fff=0;
			while(l<=r&&r<=start+len-1){
				if(r+1>=f&&!fff){
					cntt++;
					fff=1;
//					r++;
					l=r;
				}else{
					if(a[r]-a[l]>d){
						l=r;
						cntt++;
						if(r==start+len-1){
							ff=1;
						}
					}else{
						if(r==start+len-1){
							cntt++;
						}
						r++;
					}
				}
			}
			if((cntt!=cnt)||ff){
//				if(start==1&&len==3){
//					cout<<"a"<<f<<' '<<cnt<<' '<<cntt<<endl;
//					cout<<start<<" "<<start+len-1<<endl;
//				}
				continue;
			}
			int in=cntt; 
			l=start,r=start;
			cntt=0;
			ff=fff=0;
			while(l<=r&&r<=start+len-1){
				if(r+2>=f&&!fff){
					cntt++;
//					r++;
					fff=1;
					l=r;
				}else{
					if(a[r]-a[l]>d){
						l=r;
						cntt++;
						if(r==start+len-1)ff=1;
					}else{
						if(r==start+len-1){
							cntt++;
						}
						r++;
					}
				}
			}
			if((cntt!=cnt)||ff){
//				cout<<f<<" "<<cnt<<' '<<in<<' '<<cntt<<endl;
//				cout<<start<<" "<<start+len-1<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>test>>t;
	while(t--){
		solve(); 
	}
    return 0;
}

