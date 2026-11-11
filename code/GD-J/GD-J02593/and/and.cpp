#include<bits/stdc++.h>
using namespace std;
int nn1,mm1;
int maxxn;
int aa1[200015];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out"."w",stdout);
	cin>>nn1>>mm1;
	for(int i=1;i<=nn1;i++){
		cin>>aa1[i];
	}
	if(mm1==1){
		for(int i=1;i<=nn1;i++){
			maxxn=max(aa1[i],aa1[i+1]);
		}
	}else if(mm1==2){
		for(int i=1;i<=nn1;i++){
			int ans=aa1[i];
			for(int j=1;j<=nn1;j++){
				maxxn=max(ans&aa1[j],ans&aa1[j+1]);
			}
		}
	}else if(mm1==nn1){
		maxxn=aa1[1];
		for(int i=1;i<=nn1;i++){
			maxxn=maxxn&aa1[i];
		}
	}
	cout<<maxxn;
	return 0;
}
