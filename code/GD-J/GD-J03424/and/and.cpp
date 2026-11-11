#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,t,cnt;
bool flag=true;
struct node{
	long long b;
	string w;
}a[200005];
string f,t1,t2;
bool cmp(node x,node y){
	return x.b>y.b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","l",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++) cin >>a[i].b;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		f="0000000000";
		t=a[i].b;
		t1="";
		while(t>0){
			t1+=(t%2+'0');
			t/=2;
		}
		if (a[i].b<4) t1+="0";
		reverse(t1.begin(),t1.end());
		f+=t1;
		a[i].w=f;
	}
	for (int i=0;i<=30;i++){
		cnt=0;
		for (int j=1;j<=n;j++){
			t2=a[j].w;
			if (t2[i]=='1') cnt++;
			if (cnt>=m){
				ans=j;
				flag=false;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag){
		cout <<"0";
		return 0;
	}
	sum=a[ans].b;
	for (int i=ans-m;i>ans;i--){
		sum=sum&a[i].b;
	}
	cout <<sum;
	return 0;
}
