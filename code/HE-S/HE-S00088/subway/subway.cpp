#include<iostream>
using namespace std;
const int N=50000;
int n,d,a[N],num[N],val[N],ans[N];
void dfs(int s,int tim){

	if(val[s]==tim) ans[s]++;
	if(val[s]<tim) return;
	if(val[s]<tim){
		val[s]=tim;
	ans[s]=1;
	}
	int r=s;
	while(r<=n&&a[r]-a[s]<=d)
	for(int i=r;i>s;i--) 
}
int main(){
	ios::sync_with_stdio[0];
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	int sum=0
    	for(int i=1;i<=n;i++){
    		dfs[i,0];
    		val[i]=0;
    		ans[i]=0;
    		for(int j=1;i<=n;j++) sum+=(ans);
		}
	}
	cout<<sum<<"\n"
    return 0;
}
