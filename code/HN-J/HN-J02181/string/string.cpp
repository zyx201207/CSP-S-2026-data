#include<bits/stdc++.h>
using namespace std;
int n,an[200010],l,r;
long long ans;
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>an[i]>>a[i];
	}
	for(int i=1;i<=n;i++){
		int amin=min(an[l],an[r]);
		if(l==r){
			cout<<ans;
			return 0;
		}
		if(a[l]==a[r]){
			an[l]-=amin;
			an[r]-=amin;
			if(an[l]==0) l++;
			else r--;
		}
		else{
			ans+=amin;
			an[l]-=amin;
			an[r]-=amin;
			if(an[l]==0) l++;
			else r--;
		}
	}
	
}
