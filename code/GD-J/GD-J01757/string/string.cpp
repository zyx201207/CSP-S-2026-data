#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
const int M=1e6+10;
const int K=15;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
int n;
struct node{
	int a;
	char c;
}val[N];
int st[N],len;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	st[1]=1;
	for(int i=1;i<=n;++i){
		cin>>val[i].a>>val[i].c;
		st[i+1]=st[i]+val[i].a;
		len+=val[i].a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
//	for(int i=1;i<=n;++i){
//		cout<<st[i]<<" ";
//	}
//	cout<<endl;
	int id=n,pos=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=st[i],r=st[i]+val[i].a-1;
		int cnt=val[i].a;
		if(len/2<l)break;
//		cout<<"i:"<<i<<endl;
		while(1){
			if(id==i)break;
//			cout<<"id:"<<id<<" pos:"<<pos<<endl;
//			cout<<"cnt:"<<cnt<<endl;
			if(pos+cnt<=val[id].a){
				pos+=cnt;
				if(val[id].c!=val[i].c)ans+=cnt;
				if(pos==val[id].a)id--,pos=0;
				break;
			}else{
				if(val[i].c!=val[id].c){
					ans+=val[id].a-pos;
				}
				cnt-=val[id].a-pos;
				id--;
				pos=0;
			}
		}
//		cout<<"id:"<<id<<" pos:"<<pos<<endl<<endl;
	}
	cout<<ans;
	return 0;
}
/*
6
1 b
1 a
1 b
1 a
2 b
2 c

bababbcc
*/
