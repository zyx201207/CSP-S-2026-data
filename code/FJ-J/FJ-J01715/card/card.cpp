#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
ll n,m,a[N],last[M];
bool flag=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card4.in","r",stdin);//调试用
//	freopen("card.out","w",stdout);//调试用
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i>1)flag=true;
	}
	if(m==1)cout<<n;
	else if(m==2){
		if(a[n]==1){
			ll lst=0,las=0;
			for(int i=n;i>0;i--){
				if(a[i]==2){
					lst=i;
					break;
				}
			}
			for(int i=lst;i>0;i--){
				if(a[i]==1)las=i;
			} 
			cout<<n<<" "<<lst-las;
		}else{
			ll lst=0,las=0;
			for(int i=n;i>0;i--){
				if(a[i]==1){
					lst=i;
					break;
				}
			}
			for(int i=lst;i>0;i--){
				if(a[i]==2)las=i;
			} 
			cout<<lst-las<<" "<<n;
		}
	}else if(!flag){
		for(int i=1;i<=n;i++){
			last[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<last[i]<<" ";
		}
	}
	
	return 0;
}

