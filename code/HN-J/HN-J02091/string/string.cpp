#include<bits/stdc++.h>
using namespace std;
long long a,b,num;
string c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		cin>>c;
		for(int i=1;i<=b;i++){
			d+=c;
		}
	}
	for(int i=0;i<d.size()/2;i++){
		for(int j=d.size()/2;j>0;j--){
			if(d[i]!=d[j]){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

