#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,t[100005110];int x;char c;ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
		int num=1;
		for(int i=1;i<=n;i++){
			cin>>x>>c;
			int tmp=num;
			for(;num<=x+tmp-1;num++)t[num]=c;
		}
		num--;
		for(int i=1,j=num;i<=j;i++,j--){
			if(t[i]!=t[j])ans++;
		}
		cout<<ans;
		return 0;
}
//EXP:68pts
//1GB = 2*10^8 int
