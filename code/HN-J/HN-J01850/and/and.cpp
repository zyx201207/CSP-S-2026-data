#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005][5][40];
int maxx=0;
void zh(int b,int it){
	int c[50]={};
	int i=1;
	a[it][2][2]=b;
	while(b!=0){
		c[i]=b%2;
		b/=2;
		i++;
	}
	int f1=1;
	for(int f=i-1;f>=1;f--){
		if(c[f]==0){
			a[it][1][f1]=-1;
		} else{
			a[it][1][f1]=c[f];
		}
		

		f1++;
		 
	}
	a[it][2][1]=i-1;

}
int zhixz[200005];
int pd(int qs,int sz){
	if(qs>m){
	int zdz=0,dqsum=0;
		for(int i=1;i<=m;i++){
			zdz=max(a[i][2][1],zdz);
		}
		for(int i=1;i<=zdz;i++){
			for(int i1=2;i1<=m;i1++){
				if(a[zhixz[i1]][1][i]==a[zhixz[i1-1]][1][i]){
	
					if(i1==m){
						int cs=a[zhixz[i1]][1][i];
						if(cs==-1){
							cs=0;
						}
						
						for(int i3=1;i3<i;i3++){
							cs=2*cs;
						}
						dqsum+=cs; 
					}
					continue;
				}else{

					break;
				}
			
			}
		}

		maxx=max(dqsum,maxx);
	}
	for(int i=sz;i<=n;i++){
		zhixz[qs]=i;
		pd(qs+1,i+1);
		zhixz[qs]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		zh(t,i);
	}
	pd(1,1);
	cout<<maxx; 
	return 0;
} 
