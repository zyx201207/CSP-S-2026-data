#include<bits/stdc++.h>
using namespace std;
int n,c,sd=1,ans;
char a[1000000000];
char l;
//struct m{
//	int a;
//	char b;
//}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		cin>>l;
		for(int j=1;j<=c;j++){
			a[sd]=l;
			sd++;
		}
	}
	sd--;
	for(int i=1;i<=sd/2;i++){
		if(a[i]!=a[sd-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
