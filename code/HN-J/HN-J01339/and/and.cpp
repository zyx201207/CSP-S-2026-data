#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long max=0,w=0;
	long long o[a];
	for(int i=0;i<=a-1;i++){
		cin>>o[i];
	}
	if(b==1){
		for(int i=0;i<=a-1;i++){
			if(b<o[i]){
				b=o[i];
			}
		}
		cout<<b;
		return 0;
	}
	for(int i=0;i<=a-2;i++){
		if(o[i]==o[i+1]){
			w=o[i];
		}
		if(max<w){
			max=w;
		}
	}
	cout<<max;
	return 0;
}
