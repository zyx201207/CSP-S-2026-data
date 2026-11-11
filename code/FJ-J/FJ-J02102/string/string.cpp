#include<bits/stdc++.h>
using namespace std;
long long n,i[200005],h,g,id;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>i[j]>>a[j];
		g+=i[j];
	}
	for(int j=1,p=0;j<=n;j++){
		if(p>=g/2){
			id=j;
			break;
		}
		p+=i[j];
	}
	bool b=0;
	int l;
	if(g%2==0){
		l=g/2+1;
	}else{
		l=g/2+2;
	}
	for(int j=l;j<=g;j++){
		for(int k=1;k<=n/2;k++){
			if(a[id]==a[k]){
				b=1;
				break;
			}
		}
		if(b==0){
			h++;
			if(j>i[id]){
				id++;
			}
		}
	}
	cout<<h;
	return 0;
}
