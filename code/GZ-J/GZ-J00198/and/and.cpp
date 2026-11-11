//GZ-J00198 遵义市第一初级中学 黄君豪
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	int c[101]={0};
	int k=0;
	int b[101]={0};
	string s;
	int o=0;
	for(int i=0;i<n;i++){
		cin>>a;
		o=a;
		while(a!=0){
			c[k]=a%2;
			a/=2;
			k++;
			b[i]++;
		}
		k++;
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
}


