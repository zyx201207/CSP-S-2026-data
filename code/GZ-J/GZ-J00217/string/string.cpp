//GZ-J00217,金沙第一中学，姓名：王俊泽 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e+5;
int n,m=1;
long long f=0;
int a[maxn],b[maxn],c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[m]=c[i];
			m++;
		}
	}
	for(int i=1;i<=1;i++){
		for(int j=1;j<=n;j++){
			if(c[i]==c[j]){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(b[i]!=b[1]){
			f++;
		}
	}
	cout<<f<<endl;
	return 0;
}
