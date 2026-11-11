#include<bits/stdc++.h>
using namespace std;
const int N1=5e5+10,N2=3e5+10;
struct aaa{
	int id;
	bool b=0;
}b[N2];

long long n,m,a[N1],ans[N2],pai=1;

stack<int> c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[a[pai%n]].b){
				for(int k=c.size();k>=b[a[pai%n]].id;k--){
					if(c.size()>0) c.pop();	
				} 
			}else{
				b[a[pai%n]].b=1;
				b[a[pai%n]].id=c.size();
			} 
			c.push(a[pai%n]);
			ans[a[pai%n]]++;
			pai++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
