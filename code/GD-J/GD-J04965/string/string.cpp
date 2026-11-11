/*
两端压缩，用大的减小的
3 a ->0 a -> 0 a
4 c ->4 c -> 0 c
10 b->7 b -> 3b
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,z;
};
node num[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>num[i].x>>c;
		num[i].z=c-'a'+1;
	}
	int cnt=0,l=1,r=n;
	while(l<r){
		if(num[l].x<num[r].x){
			if(num[l].z!=num[r].z){
				cnt+=num[l].x;
			}
			num[r].x-=num[l].x;
			l++;
		}
		else {
			if(num[l].z!=num[r].z){
				cnt+=num[r].x;
			}
			num[l].x-=num[r].x;
			if(num[l].x==0){
				l++;
			}
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
