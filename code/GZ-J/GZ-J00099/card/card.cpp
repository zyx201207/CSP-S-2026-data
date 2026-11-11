//GZ-J00099 ¶Å³¿¼Î 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int mn[500001],l=0;
bool lly[300001];
int mm[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(lly,0,sizeof(lly));
		int o=n-i+1;
		l=0;
		for(int j=o;j<=n;j++){
			l++;
			mn[l]=a[j];
			if(lly[a[j]]==1){
				int mb=0;
				for(int p=1;p<=l;p++){
					if(mn[p]==a[j]){
						mb=p;
						break;
					}
				}
				for(int p=mb+1;p<=l;p++){
					mn[p]=0;
				}
				l=mb+1;
			}else{
				lly[a[j]]=1;
			}
			
		}
		for(int j=1;j<=l;j++){
			mm[mn[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	return 0;
}
