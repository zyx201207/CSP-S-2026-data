#include<bits/stdc++.h>
using namespace std;
int n,m,a[300100],x=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	while(n--){
		vector<int> b;
		int c[300100]={0};
		for(int i=x;i<=n;i++){
			c[a[i]]++;
			if(c[a[i]]>1){
			}else{
				b.push_back(a[i]);
			}
		}
	}
	return 0;	
}
