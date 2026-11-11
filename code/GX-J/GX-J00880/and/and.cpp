#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int a[200010];
int m;
bool qwq(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//pian fen
	//cout<<(15|12)<<" "<<(15&12)<<endl;
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m<=2){
		if(m==1){
			cout<<mx<<endl;
			return 0;
		}
		else{
			mx=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					mx=max(mx,(a[i]&a[j]));
					//cout<<a[i]<<" "<<a[j]<<" "<<mx<<endl;
				}
			}
			cout<<mx<<endl;
			return 0;
		}
	}
	sort(a+1,a+n+1,qwq);
	mx=a[1];
	for(int i=2;i<=m;i++){
		mx=mx&a[i];
	}
	cout<<mx<<endl;
	return 0;
}
