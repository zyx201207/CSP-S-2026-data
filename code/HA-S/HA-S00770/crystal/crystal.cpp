#include<bits/stdc++.h>
using namespace std;
int n,m,ma=-0x3f3f3f3f;
long long a[10000005];
void abs(int sum,int cnt,int mubiao){
	if((sum*1.0+m)/cnt==mubiao*1.0){
		if(cnt>ma){
			ma=cnt;
		}
		return ;
	}
	for(int i=cnt;i<=n;i++){
		abs(sum+a[i],cnt+1,a[i]);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	abs(0,1,a[1]);
	cout<<ma;
	return 0;
}
