#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
struct node{
	long long num;
	char ch;
}k[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i].num>>k[i].ch;
	}
	long long l=1,r=n,ans=0;
	while(l<=r){
		//cout<<l<<' '<<r<<'\n';
		
		while(k[l].num==0&&l<r)l++;
		while(k[r].num==0&&l<r)r--;
		if( l==r)break;
		if(k[l].ch==k[r].ch){
			long long minn=min(k[l].num,k[r].num);
			k[l].num-=minn;
			k[r].num-=minn;
		}
		else{
			long long minn=min(k[l].num,k[r].num);
			k[l].num-=minn;
			k[r].num-=minn;
			ans+=minn;
		}
		//printf("%d %d %lld\n",l,r,ans);
	}
	cout<<ans;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
