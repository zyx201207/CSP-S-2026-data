#include<bits/stdc++.h>
using namespace std;

int n,m;
int big,small;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		big=max(big,tmp);
		small=min(small,tmp);
	}
	int ans=0;
	int flag=0;
	while(m>0){
		m-=flag;
		flag++;
		ans++;
	}
	if(m<0)ans--;
	cout<<ans;
	return 0;
}
