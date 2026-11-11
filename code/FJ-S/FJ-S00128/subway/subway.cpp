#include<bits/stdc++.h>
using namespace std;
int w[100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a1,a2,a3,a4,a5;
	cin>>a1>>a2>>a3>>a4>>a5;
	for(int i=1;i<=a3;i++)
	{
		cin>>w[i];
		
		
		
	}
	int x;
	for(int i=1;i<=2*(a3+2);i++){
		cin>>x;
	}
	int u,y;
	for(int i=1;i<=2;i++){
		cin>>u>>y;
		cout<<w[i]*(y-u)<<endl;
	}
	return 0;
}
