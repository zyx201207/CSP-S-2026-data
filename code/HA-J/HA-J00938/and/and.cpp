#include<bits/stdc++.h>
using namespace std;
int ls[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>ls[i];
	}
	sort(ls+1,ls+y+1);
	cout<<ls[3];
	return 0;
}
