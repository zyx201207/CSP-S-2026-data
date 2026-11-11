#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	vector<int>s(300001,0),a(500001),b(500001),c(500001);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int k=1;k<=n;k++){
		b.clear();
		for(int i=k;i<=n;i++){
			if(i>k&&find(b.begin(),b.end(),a[i])!=b.end()){
				c.clear();
				for(auto &j:b){
					if(a[i]==j)
						break;
					c.push_back(j);
				}
				b=c;
			}
			b.push_back(a[i]);
		}
		for(auto &i:b)
			s[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<s[i]<<' ';
	return 0;
}
