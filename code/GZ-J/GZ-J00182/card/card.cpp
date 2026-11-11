//GZ-J00182 北京师范大学贵阳附属中学 赵瀚成 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],x[500010],l=0,s=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int nb=n;
		for(int j=0;j<n;j++){
			s=0;
			for(int k=0;k<l;k++){
				if(x[k]==a[j]&&s!=1){
					k=0;
					s=1;
					c=x[k];
					continue;
				}
				if(x[k]>=c){
					x[k]=0;
				}
			}
			
		}
	}
	return 0;
}
