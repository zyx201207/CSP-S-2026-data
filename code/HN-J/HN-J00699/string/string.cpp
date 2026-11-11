#include<bits/stdc++.h>
using namespace std;

struct node{
	long long a;
	char b;
	int x,y;
};
node sn[200005];

long long n,ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sn[i].a>>sn[i].b;
		sn[i].x=sn[i-1].y+1;
		sn[i].y=sn[i].x+sn[i].a-1;
	}
	long long l=1,r=n,sum=0,num=0;
	sum+=sn[l].a;
	num+=sn[r].a;
	while(1){
		if(l>=r){
			break;
		}
		if(sn[l].b!=sn[r].b){
			ans+=min(sum,num);
		}
		if(sum==num){
			l++,r--;
			sum=sn[l].a;
			num=sn[r].a;
		}else if(sum<num){
			l++;
			num-=sum;
			sum=sn[l].a;
		}else{
			r--;
			sum-=num;
			num=sn[r].a;
		}
	}
	cout<<ans;
	return 0;
}
