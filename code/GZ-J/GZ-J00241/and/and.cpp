//GZ-J00241 个人报名 吴狄阳 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-m+1;j++){
			int l=a[j];
			for(int k=1;k<m;k++){
				l=l&a[j+k];
				p=max(p,l);
			}
		}
	}
	cout<<p;
}
