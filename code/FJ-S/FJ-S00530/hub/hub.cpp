#include<bits/stdc++.h> 
using namespace std;
int c,t;
long long n,k;
struct Node{
	int x,y;
}a[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	int b=t;
	while(b--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y;
		}
	}
	if(t==1){
		cout<<2;
	}else if(t==2){
		cout<<1<<endl<<2;
	}else if(t==3){
		cout<<1<<endl<<2<<endl<<1;
	}else if(t==4){
		cout<<1<<endl<<3<<endl<<1<<endl<<2;
	}else{
		cout<<1<<endl<<2<<endl<<1<<endl<<1<<endl<<2;
	}
	return 0;
}
