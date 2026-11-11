#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int a;
	cin>>a;
	int b=0;
	int c,d;
	for(int i=0;i<a;i++0){
		cin>>d>>c;
		b+=c;
	}
	b=b/a;
	b=b*0.9;
	cout<<b;
}
