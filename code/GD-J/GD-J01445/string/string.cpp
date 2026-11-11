#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char m[1000005];
	long long a=0,b=0,c=0,C=1,D=0,ans=0;
	char d;
	cin>>a;
	if(a==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=a;i++){
		cin>>c>>d;
		for(int j=C;j<C+c;j++){
			m[j]=d;
		}
		C=C+c;
		b+=c;
	}
	if(b%2==0){
		for(int i=1,j=b;i<=b/2;i++,j--){
			if(m[i]!=m[j]){
				ans++;
			}
		}
	}
	else if(b%2==1){
		for(int i=1,j=b;i!=j;i++,j--){
			if(m[i]!=m[j]){
				ans++;
			}
		}
	}
	cout<<ans;
}
