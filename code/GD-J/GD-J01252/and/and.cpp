#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
long long a[200005],dp[200005],mx,li;
 map<long long,int>mp;
int n,m;
long long mi(long long a,long long b){
	if(a<b)return a;
	return b;
}
long long ma(long long a,long long b){
	if(a>b)return a;
	return b;
}
void dfs(int id,int c,long long num){
	if((a[id]|(1<<li))==0)return;
	if(c==m){
	mx=ma(mx,num);
	return;
}
if(id>n)return;
	dfs(id+1,c+1,num&a[id]);
	dfs(id+1,c,num);
}
int main(){
	//memset(dp,0x3f,sizeof(dp));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    long long mnid=0;
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
    	long long id=0;
    	while(a[i]>=(1<<id)){
    		if((a[i]|(1<<id))!=0)mp[id]++;
    		id++;
		}
		mnid=ma(mnid,id-1);
    }
    while(mnid>=0){
    	if(mp[mnid]>=m){
    		li=mnid;
    		break;
		}
		mnid--;
	}
	for(int i=1;i<=n;i++){
		if((a[i]|(1<<li))==0)continue;
	dfs(i+1,1,a[i]);
}
    cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
