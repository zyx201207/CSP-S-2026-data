#include<bits/stdc++.h>
using namespace std;
struct he{
	string s;
	int num=0;
}h[300000];
bool cmp(he a,he b){
	if(a.num==b.num)return a.s>b.s;
	return a.num>b.num;
}
long long cn[100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0,y=1,a[300005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		while(x>1){
			h[i].s+=x%2+'0';
			x/=2;
		}
		h[i].s+='1';
		for(int j=1;j<=h[i].s.size();j++){
			if(h[i].s[j]=='1'){
				h[i].num++;
			}
		}
	}
	sort(h+1,h+1+n,cmp);
	int maxx=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=h[i].s.size();j++){
			if(h[i].s[j]=='1'){
				cn[j]++;
				maxx=max(maxx,j);
			}
		}
	}
	for(int i=0;i<=maxx;i++){
		if(cn[i]==m){
			cnt+=y;
		}
		y*=2;
	}
	cout<<cnt;
}
