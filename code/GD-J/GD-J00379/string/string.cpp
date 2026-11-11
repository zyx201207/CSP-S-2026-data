#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
ll n,a[N],b[N];
char c[N],ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int m=0;
	c[0]='#';
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]){
			b[++m]=a[i];
			ch[m]=c[i];
		}else b[m]+=a[i];
	}
	ll res=0; 
	for(int i=1,j=m;i<=j;){
		if(ch[i]!=ch[j]){
			res+=min(b[i],b[j]); 
			if(b[i]==b[j]) i++,j--;
			else if(b[i]<b[j]) b[j]-=b[i],i++;
			else if(b[i]>b[j]) b[i]-=b[j],j--;
		}else{
			if(b[i]==b[j]) i++,j--;
			else if(b[i]<b[j]) b[j]-=b[i],i++;
			else if(b[i]>b[j]) b[i]-=b[j],j--;
		}
	}cout<<res;
	return 0;
}
