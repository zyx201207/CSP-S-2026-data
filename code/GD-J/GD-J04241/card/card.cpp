#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,c[500005];
bool b[500005];
deque<int> d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				while(!d.empty()){
					d.pop_back();
					if(d.front()==a[j]){
						d.pop_back();
						break;
					}
				}
			}
			d.push_back(a[j]);
			b[a[j]]=1;
		}
		while(!d.empty()){
			c[d.front()]++;
			d.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
