#include<bits/stdc++.h>
using namespace std;
struct yz{
	int num;
	char zimu;
}yz[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>yz[i].num>>yz[i].zimu;
	}
	int b=1,c=n;
	long long a=0;
	while(true){
		if(c<=b) break;
		if(yz[b].num > yz[c].num){
			if(yz[b].zimu != yz[c].zimu){
				a+=yz[c].num;
			}
			yz[b].num-=yz[c].num;
			c--;
		}
		else{
			if(yz[b].zimu != yz[c].zimu){
				a+=yz[b].num;
			}
			yz[c].num-=yz[b].num;
			b++;
			if(yz[c].zimu==0){
				c--;
			}
		}
	}
	cout<<a;
	return 0;
}
