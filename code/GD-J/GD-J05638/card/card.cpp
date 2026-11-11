#include<bits/stdc++.h>
using namespace std;
int p[500010],a[500010],t[300010],n,m,t2[300010],t3[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){//¾Ö 
		int id=1;
		for(int j=i;j<=n;j++){//ÅÆ 
			if(t2[p[j]]==0){
				a[id]=p[j];
				t2[p[j]]=id;
				id++;
			}else{
				int l=t2[p[j]];
				for(int k=l+1;k<=id;k++){
					a[k]=0;
					t2[p[k]]=0;
				}
				for(int k=1;k<=id;k++){
					if(t2[a[k]]==0)t2[a[k]]=k;
				}
				id=l+1;
			}
//			for(int k=1;k<=id;k++){
//				cout<<a[k]<<"   ";	
//			}
//			cout<<endl;
	}
		for(int j=1;j<=id;j++){
//			cout<<a[j]<<" ";
			t3[a[j]]=1;
		}
//		cout<<endl;
		for(int j=1;j<=m;j++){
			t[j]+=t3[j];
			t2[j]=0;
			t3[j]=0;
		}
		for(int j=1;j<=n;j++){
			a[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
