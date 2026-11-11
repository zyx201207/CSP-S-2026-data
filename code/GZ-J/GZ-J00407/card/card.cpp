//李杜文谦 GZ-J00407 清镇市广大实验学校
#include <bits/stdc++.h>
using namespace std;
const int N=5e5+15;
int n,m;
char s[N];
int a[N];
bool d;
signed main(){
	freopen("crad.in","r",stdin);
	freopen("crad.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<n;i++){
		if(!(s[i]<=s[i+1])){
			d=1;
		}
	}
	if(!d){
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i+1]){
				a[int(s[i]-'0')]=i;
			}
		}
		for(int i=1;i<=m;i++)cout<<a[i]<<' ';
		return 0;
	}
	int l=1;
	for(int i=n;i>=1;i--){
		int r=l;
		while(r<=n){
			bool flag=0;
			for(int j=r+1;j<=n;j++){
				if(s[j]==s[r]){
					r=j;
					flag=1;
					break;
				}
			}
			if(!flag){
				a[int(s[r]-'0')]++;
				r++;
			}
		}
		l++;
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;	
}
