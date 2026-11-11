//GZ-J00607 刘祚诚 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n,m,s[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}


