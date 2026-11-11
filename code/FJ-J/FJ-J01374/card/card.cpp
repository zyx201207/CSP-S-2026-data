#include<bits/stdc++.h>
using namespace std;
long long n,m,a[501010],b[501010],c[501010];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				while(!s.empty()){
					if(s.top()==a[j]){
						break;
					}
					c[s.top()]--;
					s.pop();
				}
			}else{
				c[a[j]]++;
				s.push(a[j]);
			}
		}
		while(!s.empty()) s.pop();
		for(int i=1;i<=m;i++) {
			b[i]+=c[i];
			c[i]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
} 
