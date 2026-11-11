#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n,a[N],l_1,r_1,l_2,r_2;
char s[N];
ll ans=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	l_1=1,l_2=a[1],r_1=n,r_2=a[n];
	while(l_1<r_1){
		if(r_2>l_2){
			r_2-=l_2;
			if(s[l_1]!=s[r_1]) ans+=l_2; 
			l_1++,l_2=a[l_1];
		}else if(r_2==l_2){
			if(s[l_1]!=s[r_1]) ans+=l_2;
			l_1++,l_2=a[l_1],r_1--,r_2=a[r_1];
		}else{
			l_2-=r_2;
			if(s[l_1]!=s[r_1]) ans+=r_2; 
			r_1--,r_2=a[r_1];
		}
	}
	cout<<ans;
	return 0;
}
