#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
	int num;char c;
}a[N];
int n,ans,cnt=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char c;cin>>x>>c;
		if(i==1){
			a[++cnt].num=x,a[cnt].c=c; 
		}else{
			if(a[cnt].c==c){
				a[cnt].num+=x;
			}else{
				a[++cnt].num=x,a[cnt].c=c;
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<a[i].num<<' '<<a[i].c<<endl;
//	}
	int l=1,r=cnt;
	while(l<r){
		if(a[l].c==a[r].c){
			int t=min(a[l].num,a[r].num);
			a[l].num-=t,a[r].num-=t;
			if(a[l].num==0)l++;
			if(a[r].num==0)r--;
		}else{
			int t=min(a[l].num,a[r].num);
			ans+=t;
			a[l].num-=t,a[r].num-=t;
			if(a[l].num==0)l++;
			if(a[r].num==0)r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
