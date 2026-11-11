//GZ-J00253 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,m,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<n;i++){
			if(a[i]!=a[n]) cnt++;
		}
		if(a[n]==1) cout<<n<<" "<<cnt<<endl;
		else cout<<cnt<<" "<<n<<endl;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) cout<<i<<" ";
		}
	}
}
