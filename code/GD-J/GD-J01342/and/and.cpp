#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll ma,ma2,a[200005];
bool vis[200005];
ll and_1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>ma){
				ma=(a[i]&a[j]);
				vis[i]=true;
				vis[j]=true;
			}
		}
	}
	return ma;
}
void and_2(ll ma){
	for(int i=1;i<=n;i++){
		if((ma&a[i])&&vis[i]==false){
			ma2=(ma&a[i]);
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	and_1();
	if(m<=2)cout<<ma;
	else{
		for(int i=1;i<m-1;i++)and_2(ma);
		cout<<ma2;
	}
	return 0;
}
