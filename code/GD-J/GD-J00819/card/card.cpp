#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],d[1000000];
bool c[1000000];
 <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s.push(a[j]);
			b[a[j]]++;
			if(b[a[j]]>=2){
				while(b[a[j]]){
					b[s.top()]--;
					s.pop();
				}
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			c[s.top()]=true;
		}
		d[i]+=c[i];
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
