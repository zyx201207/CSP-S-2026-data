#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,a[N],me,ans;
bool flagsamec=1; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flagsamec=0;		
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "; 
//	}
//	cout<<endl;
	for(int k=1;k<=n;k++){
		me=a[k];
		int pos=1,sum=m;
		for(int i=k+1;i<=n;i++){
			//val me 		cnt i-1
			if(a[i]==a[i-1]){
				pos=i;
				continue;
			}
			int cnt=i-1;
			//me->a[i]
			int cost=(a[i]-me)*cnt;
			if(cost<=sum){
				sum-=cost;
				pos=i;
				me=a[i];
			}else{
				break;
			}
		}
		ans=max(ans,pos-k+1);
		if(flagsamec)	break;
	}
	cout<<ans;
	
	
	
	
	
	return 0;
}
/*
Ì°ÐÄ£¬14£º47¿ªµ÷ 
45+25=70


5 5
1 2 4 8 9

5 8
-3 -1 2 2 7



3 4
1 200 201 






*/

