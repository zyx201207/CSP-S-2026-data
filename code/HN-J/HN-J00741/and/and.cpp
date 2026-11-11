#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int s=-0x3f3f3f3f;
void f(int t,int j,int y=1){
	if(y==m){
		//cout<<t<<' ';//
	s=max(t,s);
	//cout<<"?"<<s<<" "<<t<<" ";//
	//cout<<endl;//
		return;
	}
	for(int i=j+y;i<=n;i++){
		//cout<<t<<" ";//
		//cout<<a[i]<<" ";//
		//cout<<y<<" "; //
		f(t&a[i],i,y+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<" ";//
	f(a[i],i);	
	//cout<<endl;//
	}
	cout<<s;
	return 0;
	}
//Trick||Treat!
//
