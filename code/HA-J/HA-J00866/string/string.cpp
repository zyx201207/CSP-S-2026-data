#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m;
	char a;
	int sum=n;
	int num=0;
	for(int i=1;i<=n;i++){
		sum*=m;
		cin>>m;
		cin>>a;
		for(int i=1;i<=m;i++){
			b[num+i]=a;
		}
		num+=m;
	}
	int ans=0;
	for(int i=0;i<num/2;i++){
		if(b[num/2+i]!=b[num/2-i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
