#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,cnt=0;
	cin>>n;
	string r,a;
	for(int i=1;i<=n;i++){
		cin>>m>>r[i];
		for(int j=0;j<m;j++){
			a[j]==r[i];
		}
	}
	int len=a.size();
	for(int i=0;i<len;i++){
		for(int j=len-1;j>=0;j--){
			if(i+j==len-1&&a[i]!=a[j]){
				a[j]=a[i];
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
