#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c,mid=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1) cout<<1;
	else{
		int c=1,c_1=2,cnt=0,cnt_1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==c) cnt++;
			else cnt_1++;
		}
		if(cnt==n) cout<<1;
		else if(cnt_1==n) cout<<2;
		else cout<<"1 2";
	}
	return 0;
}
