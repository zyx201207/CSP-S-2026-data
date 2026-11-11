#include<bits/stdc++.h> 
using namespace std;
long long n,ls,rs,ans;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].c;
	for(int i=1,j=n;i<=j;){
		if(a[i].c!=a[j].c){
			ans+=min(a[i].s,a[j].s);
			//if(a[i].s>a[j].s)
			//	a[i].s-=a[j].s;
			//else
				//a[j].s-=a[i].s;
		}
		if(a[i].s>a[j].s)
			a[i].s-=a[j].s,j--;
		else if(a[i].s<a[j].s)
			a[j].s-=a[i].s,i++;
		else
			i++,j--;
	}
	cout<<ans<<'\n';
	return 0;
}

