#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[10005],max1=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(b==2){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if((c[i] & c[j]) >max1){
					max1=(c[i] & c[j]);
				}
			}
		}
	}
	cout<<max1;
	return 0;
}
