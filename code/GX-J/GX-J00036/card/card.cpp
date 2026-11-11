#include<bits/stdc++.h>
using namespace std;
int a,b;
int c[500005];
int main(){
//   freopen("card.in","r",stdin);
//   freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		vector<int> d;
		for(int f=i;f<a;f++){
			d.push_back(c[f]);
			if(i>1){
				for(int k=i;k<f;k++){
					if(d[k]==d[f]){
						
					}
				}
			}
		}
	}
    return 0;
}
