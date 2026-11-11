#include<bits/stdc++.h>
using namespace std;
int n,a;
long long tap=0,leng=0;
char c;
char str[100000000000003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			str[++leng]=c;
		}
	}
	for(int i=1;i<=leng/2;i++){
		if(str[i]!=str[leng-i+1]){
			tap++;
		}
	}
	cout<<tap;
	return 0;
}
