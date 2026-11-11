#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+9;
struct node{
	int x;
	char y;
};
int b[N];
signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	node a[n+1];
	bool f=true;
	int len=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		for(int j=len+1;j<=len+a[i].x;j++){
			b[j]=a[i].y-'a';
		}
		len+=a[i].x;
		if(i!=1&&a[i].y!=a[1].y) f=false;
	} 
	if(f){
		cout<<"0";
		return 0;
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		if(b[i]!=b[len+1-i]) ans++;
	}
	cout<<ans/2<<endl;
	return 0;
}
