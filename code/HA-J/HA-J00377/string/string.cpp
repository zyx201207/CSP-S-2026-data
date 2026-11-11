#include<bits/stdc++.h>
using namespace std;
int n,a[100005],u=0;
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		s+=a[i];
		for(int x=1,y=s;x<=s/2,y>=s/2;x++,y--){
			if(c[x]!=c[y]){
				c[y]=c[x];
				u++;
			}
		}
	}
	cout<<u;
	return 0;
}
