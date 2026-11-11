#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],l,ans,k;
char c[100005];
string s;
int kkk(int x,bool f){
	if(f){
		for(int i=1;i<=n;i++){
			if(x>a[i]) x-=a[i];
			else return c[i];
		}
	}
	else{
		for(int i=n;i>=1;i--){
			if(x>a[i]) x-=a[i];
			else return c[i];
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1;i<=l/2;i++){
		if(kkk(i,1)!=kkk(l-i-1,0)) ans++,cout<<ans<<endl;
	}
	cout<<ans;
}
