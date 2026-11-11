//GZ-J00670 兴义市弘毅中学 罗金浩
#include<bits/stdc++.h>
using namespace std;
long long n,a[200050],i,k=0,cnt,j,x=0;
char c[200050],b[1000000000];
string m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	cnt=0;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(j=cnt;j<cnt+a[i];j++){
			b[j]=c[i];
		}
		cnt=cnt+a[i];
	}
	for(i=0;i<=cnt/2;i++){
		if(b[i]!=b[cnt-i-1]){
			k++;
		}
	}
	if(k==0) cout<<"0";
	else cout<<k;
	return 0;
}
