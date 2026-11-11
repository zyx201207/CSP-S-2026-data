#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
typedef struct node{
	char ch;
	int sum;
}node;
ll len=0,cnt=0;
node nd[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nd[i].sum>>nd[i].ch;
		len+=nd[i].sum;
	}
	int l=1,r=n;
	while(l!=r){
		if(nd[l].ch!=nd[r].ch){
			if(nd[l].sum<nd[r].sum){
				cnt+=nd[l].sum;
				nd[r].sum-=nd[l].sum;l++;
			}else if(nd[l].sum==nd[r].sum){
				cnt+=nd[l].sum;
				l++;r--;
			}else if(nd[l].sum>nd[r].sum){
				cnt+=nd[r].sum;
				nd[l].sum-=nd[r].sum;r--;
			}
		}else{
			if(nd[l].sum<nd[r].sum){
				nd[r].sum-=nd[l].sum;l++;
			}else if(nd[l].sum==nd[r].sum){
				l++;r--;
			}else if(nd[l].sum>nd[r].sum){
				nd[l].sum-=nd[r].sum;r--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}