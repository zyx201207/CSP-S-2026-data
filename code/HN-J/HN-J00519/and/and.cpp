#include<bits/stdc++.h>
using namespace std;
#define in long long
int n,m,a[200005],ans,flag=1,flag2=1;
void mj(int now,int step,int num){
	if(step==m){
		ans=max(ans,num);
		return ;
	}
	for(int i=now+1;i<=n;i++){
		mj(i,step+1,num&a[i]);
	}
}
bool check(int now){
	now+=1;
	int bj=1;
	while(1){
		if(now==0){
			break;
		} 
		if(now%2==0){
			now/=2;
		}
		else{
			bj=0;
			break;
		}
	}
	return bj;
}
bool cmp(int q,int h){
	return q>h;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			flag2=0;
		}
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			mj(i,1,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(check(n-1) && flag2==1){
		int ls=a[1];
		for(int i=2;i<m;i++){
			ls=ls&a[i];
		} 
		ls=ls&a[n];
		cout<<ls;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		if(!check(a[i])){
			flag=0;
			break;
		}
	}
	if(flag==1){
		sort(a+1,a+n+1);
		int ls=a[1];
		for(int i=2;i<m;i++){
			ls=ls&a[i];
		} 
		ls=ls&a[n];
		cout<<ls;
		return 0;
	} 
	sort(a+1,a+n+1,cmp);
	int num=a[1];
	for(int i=2;i<=m;i++){
		num=num&a[i];
	}
	cout<<num<<endl;
	return 0;
}
