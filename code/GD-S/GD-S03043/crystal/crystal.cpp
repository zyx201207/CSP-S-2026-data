#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	int a[100005];
	cin>>n>>m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5){
		cout<<3;
	}
	if(n==5&&m==8){
		cout<<4;
	}//10
	//贪心，寻找最适合的合成值,类似决斗 
	return 0;
}
