#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,su=0,an=0;
	cin>>n;
	string a,b;
	int c;
	
	for(int i=1;i<=n;i++){
		cin>>c>>b;
		su=su+c;
	for(int i=1;i<=c;i++){
		a=a+b;
	}	
	}
	for(int i=0;i<=su/2;i++){
		if(a[i]!=a[su-i-1]){
			an++;
		}
	}
	cout<<an;
	return 0;
}
