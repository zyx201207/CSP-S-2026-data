#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<int> c;
int b[500005];
long long cc[100005]; 
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
	cin>>n>>m;
	if(n>500&&m>200){
		for(int k=1;k<=n;k++){
			cin>>a[k];
			cc[a[k]]++;
		}
		cc[2]=cc[1]+cc[2];
		for(int k=3;k<=m;k++){
			cc[k]=cc[k-1]+cc[k-2];
		}
		for(int k=1;k<=m;k++)cout<<cc[k]<<" ";
		return 0;
	}
	for(int k=1;k<=n;k++)cin>>a[k];
	for(int r=1;r<=n;r++){
		c.clear();
		for(int k=r;k<=n;k++){
			for(int i=0;i<c.size();i++){
				if(c[i]==a[k]){
					c.erase(c.begin()+i,c.end());
					break;
				}
			}
			c.push_back(a[k]);
		}
		for(int k=0;k<c.size();k++){
			b[c[k]]++;
		}
	}
	for(int k=1;k<=m;k++)cout<<b[k]<<" ";
	return 0;
}
