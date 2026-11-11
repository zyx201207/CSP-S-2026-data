#include<bits/stdc++.h>
using namespace std;
struct node{
	long long cnt;
	char name;
};
long long l,r;
int n;
node num[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i].cnt>>num[i].name;
	}
	l=1;
	r=n;
	long long ans=0;
	while(l<r){
		if(num[l].name==num[r].name){
			if(num[l].cnt>num[r].cnt) num[l].cnt-=num[r].cnt,r--;
			else num[r].cnt-=num[l].cnt,l++;
			if(num[l].cnt==0) l++;
			if(num[r].cnt==0) r--;
		}
		else{
			if(num[l].cnt>num[r].cnt) num[l].cnt-=num[r].cnt,ans+=num[r].cnt,r--;
			else num[r].cnt-=num[l].cnt,ans+=num[l].cnt,l++;
			if(num[l].cnt==0) l++;
			if(num[r].cnt==0) r--;
		}
	}
	cout<<ans;
	return 0;
}