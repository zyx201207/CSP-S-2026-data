#include<bits/stdc++.h>
using namespace std;
#define MAXN 200001
#define int long long
struct node{
	int x;
	char y;
}s[MAXN];
node mn(int a,char b){
	node q;
	q.x=a,q.y=b;
	return q;
}int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	int a,ans=0;char b;
	for(int rp=1;rp<=n;rp++){
		cin>>a>>b;
		s[rp]=mn(a,b);
	}for(int i=1,j=n;i<=j;){
		if(s[i].y==s[j].y){
			if(s[i].x>s[j].x) {
				s[i].x-=s[j].x;
				j--;
			}else if(s[i].x==s[j].x){
				i++,j--;
			}else if(s[i].x<s[j].x){
				s[j].x-=s[i].x;
				i++;
			}
		}else{
			if(s[i].x>s[j].x) {
				ans+=s[j].x;
				s[i].x-=s[j].x;
				j--;
			}else if(s[i].x==s[j].x){
				ans+=s[i].x;
				i++,j--;
			}else if(s[i].x<s[j].x){
				ans+=s[i].x;
				s[j].x-=s[i].x;
				i++;
			}
		}
	}cout<<ans;
	return 0;
}
