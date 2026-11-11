#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],r=1,c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>1&&i!=n)r=i;
	}
	for(int i=n;i>=r;i--){
		c[a[i]]=i;
	}
	for(int i=2;i<=n;i++){
		b[a[i-1]]--;
		bool flag=0;
		if(r<i)r=i;
		if(a[r]==a[i-1]&&b[a[r]]==1){
			for(int j=r-1;j>=i;j--){
				c[j]=j-i+1;
				if(j==i)r=i;
				if(b[j]>1){
					r=j;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
