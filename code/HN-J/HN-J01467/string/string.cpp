#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10;
#define int long long
struct node{
	int x;
	char c;
}a[N];
//CCF出这么阴的题 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int ans=0,l=1,r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		r+=a[i].x;
	}
	int L=r;
	int idl=1,idr=n;
	while(idl<=idr){
		//选择删左边还是右边
		if(l<=L-r+1){//左边少从左边开始选 
			if(a[idl].x>=a[idr].x){
				if(a[idl].c!=a[idr].c){
					//两边的字母不一样要替换
					ans+=a[idr].x; 
				}
				l+=a[idr].x;
				r-=a[idr].x;
				a[idl].x-=a[idr].x;idr--;//如果左边的比右边的多直接吞掉右边的 
			}
			else{//如果还没吃完就没了
				if(a[idl].c!=a[idr].c){
					//两边的字母不一样要替换
					ans+=a[idl].x; 
				}
				l+=a[idl].x;
				r-=a[idl].x;
				a[idr].x-=a[idl].x;
				idl++;
			}
		} 
		else{
			if(a[idr].x>=a[idl].x){
				if(a[idl].c!=a[idr].c){
					//两边的字母不一样要替换
					ans+=a[idl].x; 
				}
				a[idr].x-=a[idl].x;
				l+=a[idl].x;
				r-=a[idr].x;
				idl++;
			}
			else{//如果还没吃完就没了 
				if(a[idl].c!=a[idr].c){
					//两边的字母不一样要替换
					ans+=a[idr].x; 
				}
				l+=a[idr].x;r-=a[idr].x;
				a[idl].x-=a[idr].x;
				idr--;
			}
		}
	}
	cout<<ans;
	return 0;
}

