#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//下标从0开始！！！ 从cnt结束！！！ 
	int n;cin>>n;
	string a;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;char y;
		cin>>x>>y;
		while(x--){
			a[cnt++]=y;
		}
	}cnt--;
	int l=0,r=cnt;
	int ans=0;
	while(l<r){
		if(a[l]!=a[r]){
			ans++;
		}l++;r--;
	}
	cout<<ans;
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	//下标从0开始！！！ 从cnt结束！！！ 
	int n;cin>>n;
	string a;
	int cnt=0;
	
	return 0;
}
*/
