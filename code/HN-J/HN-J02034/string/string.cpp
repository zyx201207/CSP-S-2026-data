#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005],cnt,ch,inx=1;
char c[100004];
map<int,char>b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
		for(int j=inx;j<=cnt;j++){
			b[j]=c[i];
			inx=j;
		}
	}
	int l=1,r=cnt;
	while(l<r){
		if(b[l]!=b[r]){
			ch++;
			l++;
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ch;
	
	
	
	
	return 0; 
	
}
