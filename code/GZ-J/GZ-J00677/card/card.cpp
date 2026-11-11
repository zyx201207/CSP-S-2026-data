//GZ-J00677 遵义市第十九中学 李俊希 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,a[100000]={0},t[100000]={0},lock=1,tt[100000]={0};
	char aa;
	string s="";
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>aa;
		s=s+aa;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			a[j]=s[j]-48;
			for(int y=0;y<j;y++){
				if(lock==0){
					a[y]=0;
				}
				else if(a[j]==a[y]){
					lock=0;
				}
			}
			lock=1;
		}
		for(int w=0;w<=n;w++){
			if(t[a[w]]==0){
				t[a[w]]++;
			}
		}
		for(int w=0;w<n;w++){
			a[w]=0;
			tt[w]+=t[w];
		}
		for(int w=0;w<n;w++){
			t[w]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tt[i]<<' ';
	}

	
	return 0;
}
