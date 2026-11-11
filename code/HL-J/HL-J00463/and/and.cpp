#include<bits/stdc++.h>
using namespace std;
int n,m,x,s,ans=-1,a[200010];
string b;
int ft(int x){
	int y;
	while(x){
		y*=10;
		y+=(x%2);
		x/=2;
	}return y;
}
int fh(int x){
	int y=0,l=0;
	while(x){
		y+=((x%10)*pow(2,l));
		x/=10;
		l++;
	}return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=ft(a[i]);
	}for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b="";
			int t=a[i],w=a[j];
			while(t&&w){
				if((t%10)||(w%10)) b+='1';
				else b+='0';
				t/=10;
				w/=10;
			}while(s<=b.size()){
				x=x*10+(b[s]-48);
				s++;
			}x=fh(x);
			ans=max(ans,x);
		}
	}cout<<ans;
}


