#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s,maxx;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=s&a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(m==n){
		cout<<s<<endl;
		return 0;
	}
	if(m==2){
		for(int i=2;i<=n;i++){
			maxx=max(maxx,a[i]&a[i-1]);
		}
		cout<<maxx<<endl;
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
