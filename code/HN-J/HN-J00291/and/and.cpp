#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int s[917813];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	ans=s[0];
	for(int i=0;i<m;i++){
		ans&=s[i];
	}
	cout<<ans;
    return 0;
}

