#include <bits/stdc++.h>
using namespace std;
struct s{
	int c;
	char a;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,r;
	long long ans=0;
	s a[20005];
	cin>>n;
	r=n;
	for(int i=0;i<n;i++){
		cin>>a[i].c>>a[i].a;
	}
	while(l<r){
		if(a[l].c==0){
			l++; 
		}
		if(a[r].c==0){
			r--; 
		}
		if(a[l].a==a[r].a){
			int u=min(a[l].c,a[r].c);
			a[l].c-=u;
			a[r].c-=u;
			cout<<"au="<<u<<endl;
		}else{
			int u=min(a[l].c,a[r].c);
			a[l].c-=u;	
			a[r].c-=u;
			ans+=u;
			cout<<"u="<<u<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
