#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a[100000001],cnt;
	char c[100000001], b[1000000001];
	int x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<2){
			x+=1;
			cin>>c[x];
		}else{
			x+=1;
			cin>>c[x];
			for(int j=2;j<=a[i];j++){
				x+=1;
				c[x]=c[x-1];
			}
		}
	}
	int z=1;
    for(int i=x;i>=1;i--){
    	b[i]=c[z];
    	z+=1;
	}
	for(int i=1;i<=x;i++){
		if(c[i]==b[i]){
			x++;
		}else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
