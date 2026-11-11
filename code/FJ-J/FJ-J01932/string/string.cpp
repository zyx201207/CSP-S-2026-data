#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout );
	int a;
	cin>>a;
	long long b[a];
	char c[a];
	int l=0;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		l+=b[i];
	}
	int e=0;
	int l1=b[1];
	int l2=b[a];
	int d=1;
	int cishu=0;
	int e1=a;
	for(int i=1;i<=l/2;i++){
		while(i>l1){
			d+=1;
			l1+=b[d];
		}
		while(i>l2){
			e1-=1;
			l2+=b[e1];
		}
		if(c[d]==c[e1]){
		}
		else{
			cishu+=1;
		}
	}
	cout<<cishu;
	return 0;
}
