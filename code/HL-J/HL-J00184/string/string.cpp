#include<bits/stdc++.h>
using namespace std;
string aa,bb;
int a,b[200010],f;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++) cin>>b[i]>>c[i];
	for(int i=1;i<=a;i++) f+=b[i];
	int d=1;
	for(int i=1;i<=f;i++){
		for(int j=1;j<=b[i];j++){
			aa[d]=c[i];
			d++;
		}
	}
	int e=aa.size();
	for(int i=1;i<=aa.size();i++){
		bb[i]=aa[e];
		e--;
	}
	int g=1;
	for(int i=1;i<=aa.size();i++){
		if(bb[i]!=aa[i]){
			g++;
		}
	}
	if(g%2==0){
		cout<<g;
	}
	else{
		cout<<(g+1)/2;
	}
	return 0;
}