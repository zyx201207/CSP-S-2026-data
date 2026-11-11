#include<bits/stdc++.h>
using namespace std;
long long a,b,f;
long long c[100000015];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c,c+a+1);
//	for(int i=1;i<=a;i++){
//		cout<<c[i]<<" ";
//		f+=1;
//	}
//	cout<<endl;
//	cout<<f<<endl;
	cout<<c[a-b+1];
}
