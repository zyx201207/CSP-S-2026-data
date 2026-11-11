//GZ-J00348 遵义市第十二中学 张晋宁
#include<bits/stdc++.h>
using namespace std;
int e[300005];
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int d[a+5];
	int s=0;
	for(int i=1;i<=a;i++){
		cin>>d[i];
		bool q=true;
		for(int j=1;j<=i;j++){
			if(d[i]==d[j]){
				q=false;
			}
		}
		if(q){
			s++;
		}
	}
	for(int i=1;i<=s;i++){
		cout<<i<<' ';
	}
	return 0;
}
