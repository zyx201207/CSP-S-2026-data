#include<bits/stdc++.h>
using namespace std;
bool a[222222][32];
int numb[222222];
int b[222222];
bool ita[222222];
map<long long,long long>lom2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	lom2[1]=0;
	long long asdfj=1;
	for(int i=1;i<=30;i++){
		asdfj*=2;
		lom2[asdfj]=i;
	}
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>numb[i];
		int xnu=numb[i];
		while(xnu){
			a[i][lom2[xnu&-xnu]]=1;
			xnu-=xnu&-xnu;
		}
	}
	int wei=29;
	while(wei>=0){
		
		int ism=0;
		for(int i=1;i<=n;i++){
			if(ita[i]==0&&a[i][wei]==1){
				ism++;
			}
		}
		if(ism>=m){
			for(int i=1;i<=n;i++){
				if(a[i][wei]==0){
					ita[i]=1;
				}
			}
		}
		wei--;
	}
	int ans=pow(2,30)-1;
	for(int i=1,j=0;i<=n&&j<m;i++){
		if(ita[i]==0){
			ans&=numb[i];
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
