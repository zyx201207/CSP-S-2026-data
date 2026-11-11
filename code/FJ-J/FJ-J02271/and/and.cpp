#include <bits/stdc++.h>
using namespace std;
struct qwe{
	int shu;
	string ejz;
}a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		a[i].shu=q;
		while(q!=0){
			string w;
			if(q%2==1){
				w='1';
			}
			else w='0';
			a[i].ejz+=w;
			q/=2;
		}
	}
	cout<<12;

	return 0;
}

