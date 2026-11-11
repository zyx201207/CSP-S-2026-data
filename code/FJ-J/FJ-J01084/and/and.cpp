#include<bits/stdc++.h> 
using namespace std;
int n,m,a[2*100010],v[2*100010],ans=0;
void f(int k,int s,int b){
	if(k==b){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			k++;
			int t=s;
			if(k==1) s=a[i];
			else{
				s=s&a[i];
			}
			v[i]=1;
			f(k,s,b);
			v[i]=0;
			k--;
			s=t;
		}
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int y=a[1];
		for(int i=2;i<=n;i++){
			y&=a[i];
		}
		cout<<y;
		return 0;
	}
	f(0,0,m);
	
	cout<<ans;
	return 0;
}

