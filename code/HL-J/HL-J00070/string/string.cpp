#include<bits/stdc++.h>
using namespace std;
long long ans,n,k;
char ch[10000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			k++;
			ch[k]=c;
		}
	}
	long long l=1,r=k;
	while(l<r){
		if(ch[l]!=ch[r]){
			ans++;
		}
		l++;
		r--;
	}
	printf("%d",ans);
	return 0;
}