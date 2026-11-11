#include<bits/stdc++.h>
using namespace std;
int a[200005];
struct node{
	string s;
	int onenumber;
} st[200005];
bool cmp1(node as,node ad){
	if(as.onenumber!=ad.onenumber) return as.onenumber>ad.onenumber;
	return as.s>ad.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ti=a[i];
		int chu=0;
		while(ti!=0){
			st[i].s+=char(ti%2+'0');
			chu++;
			if(ti%2==1){
				st[i].onenumber++;
			}
			ti/=2;
		}
		reverse(st[i].s.begin(),st[i].s.end());
		mx=max(mx,chu);
			}
	sort(st+1,st+1+n,cmp1);
	for(int i=1;i<=n;i++){
		cout<<st[i].s<<endl;
}
	int ans=0;
	int book[200005];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			book[i]+=int(st[j].s[i-1]-'0');
		}
	}
	
	int nb=mx-1;
	for(int i=1;i<=m;i++){
		if(book[i]==m){
			ans+=pow(2,nb);
			cout<<ans<<endl;
		}
		nb--;
	}
	cout<<ans;
	return 0;
}
