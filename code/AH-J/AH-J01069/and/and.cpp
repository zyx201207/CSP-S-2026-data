#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	int y;
}a[200005];
bool cmp(node s,node t){
	return s.y>t.y;
}
long long m,n,a1[200005],ans=0;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		long long st=a[i].x;
		while(st){
			if(st%2==1){
				a[i].y++;
			}
			st/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	cout<<ans;
    return 0;
}

