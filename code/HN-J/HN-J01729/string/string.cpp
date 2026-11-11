#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int a[N],n,ans;
char c;string s;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);//¼ÇµÃÉ¾
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;for(int j=1;j<=a[i];j++)s+=c;
	}
	int ll=1,rr=n;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){ans+=min(a[ll],a[rr]);}
		l+=min(a[ll],a[rr]);r-=min(a[ll],a[rr]);ll++,rr--;
	}
	cout<<ans;
	return 0;
}

