#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,b[200010],l,r;
char a[200010];
ll len,ans;
void cpp(){
	if(b[l]>b[r]){
		b[l]-=b[r];
		r--;
	}else if(b[r]>b[l]){
		b[r]-=b[l];
		l++;
	}else l++,r--;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		len+=b[i];
	}
	l=1,r=n;
	len/=2;
	while(1){
		if(l!=r){
			if(a[l]!=a[r])ans+=min(b[l],b[r]);
			cpp();
		}else{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
