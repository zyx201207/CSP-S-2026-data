#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ca[N],ba[N];//²î·ÖÊý×é 
int ans=-1,now_m=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ca[0]=0; 
	for(int i=1;i<n;i++){
		ca[i]=a[i]-a[i-1];
	}
	ba[0]=0;
	for(int i=1;i<n;i++){
		ba[i]=ca[i]+ba[i-1];
	}
	int head=0;
	for(int i=1;i<n;i++){
		//cout<<ba[i]-ba[head]<<'\n';
		//cout<<ba[i]<<"\n";
		if(ba[i]-ba[head]>m&&head<i){
			ans=max(ans,i-head);
			//cout<<i<<" "<<head<<"\n"; 
			head+=1;
			//cout<<1<<"\n";
		}
		else ans=max(ans,i-head+1);
		//else break;
	}
	if(ans==-1) ans=n-head;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
