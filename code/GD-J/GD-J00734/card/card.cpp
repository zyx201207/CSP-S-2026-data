#include<bits/stdc++.h>
using namespace std;
struct lll{
	int w,g;
}tt[300005];
int n,m,a[500005],t[300005],T[300005],p=0,P=0,G;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) p=1;
		if(a[i]>a[i-1]) P=1;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		int x,y,X=0,Y=0;
		for(int i=0;i<n;i++){
			x=0,y=0;
			for(int j=i;j<n;j++){
				if(x==a[j]) y=0;
				else if(x==0) x=a[j];
				else if(y==0) y=a[j];
			}
			if(x==1||y==1) X++;
			if(x==2||y==2) Y++;
		}
		cout<<X<<" "<<Y;
		return 0;
	}
	if(p==0||P==0){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				t[a[j]]++;
			}
			for(int j=1;j<=m;j++){
				if(t[j]!=0) T[j]++,t[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<T[i]<<" ";
		}
		return 0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(tt[a[j]].g==0) tt[a[j]].g=1,tt[a[j]].w=++G;
			else{
				for(int l=1;l<=m;l++){
					if(tt[l].w>tt[a[j]].w) tt[l].w=0,tt[l].g=0;
				}
			}
		}
		for(int l=1;l<=m;l++){
			if(tt[l].g>0) t[l]++,tt[l].g=0;
		}
	}
	for(int l=1;l<=m;l++){
		cout<<t[l]<<" ";
	}
	return 0;
}
