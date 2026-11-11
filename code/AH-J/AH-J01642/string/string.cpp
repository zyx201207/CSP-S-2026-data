#include<bits/stdc++.h>
using namespace std;
int n,x,ans,l;
char c;
string h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>c;
		for(int i=1;i<=x;i++) h+=c;
		l+=x;
	}
	int i=0,j=l;
	while(j>=i){
		if(h[i]!=h[j]){
			ans++;
	} 
		i++,j--;
	}
	cout<<ans;
	return 0;
}
