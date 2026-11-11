#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],mxn1=INT_MIN,s[1500][1500],add;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mxn1=max(mxn1,a[i]);
		if(i==1) add=a[i];
		else add=add&a[i];
	}
	
	if(m==1){
		printf("%d\n",mxn1);
		return 0;
	}
	if(m==n){
		int an=a[1];
		for(int i=2;i<=n;i++){
			an=an&a[i];
		}
		printf("%d\n",an);
		return 0;
	}
	if(m==n-1){
		int an,mxn3=INT_MIN;
		for(int i=1;i<=n;i++){
			if(i==1) an=a[2];
			else an=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j){
					an=an&a[j];
				}
			}
			mxn3=max(mxn3,an);
		}
		printf("%d\n",mxn3);
		return 0;
	}
	if(m==2){
		int an,mxn2=INT_MIN;
		for(int i=1;i<=n;i++){
			an=a[i];
			for(int j=i+1;j<=n;j++){
				an=an&a[j];
			}
			mxn2=max(mxn2,an);
		}
		printf("%d\n",mxn2);
		return 0;
	}
	
}
