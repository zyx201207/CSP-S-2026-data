#include<bits/stdc++.h>
using namespace std;
vector<int> v[35];
vector<int> ans1,ans2;
bool dou[200005][35];
int n,m,inans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		y=x;
		int j=0;
		while(y!=0){
			if(y%2==1) v[j].push_back(x);
			dou[i][j]=y%2;
			y/=2;
			j++;
		}
	}
	for(int i=30;i>=0;i--){
		if(v[i].size()>=m){
			if((int)ans1.size()==0){
				for(int j=0;j<(int)v[i].size();j++){
					ans1.push_back(v[i][j]);
				}
			}
			else{
				int alive=0;
				for(int j=0;j<(int)ans1.size();j++){
					if(dou[ans1[j]][i]) {
						alive++;
						ans2.push_back(ans1[j]);
					}
				}
				if(alive>=m){
					ans1.clear();
					for(int j=0;j<(int)ans2.size();j++) ans1.push_back(ans2[j]);
				}
				ans2.clear();
			}
		}
		if(ans1.size()==m) break;
	}
	inans=ans1[0];
	for(int i=1;i<(int)ans1.size();i++){
		//printf("0\n");
		inans&=ans1[i];
	}
	printf("%d",inans);
}
