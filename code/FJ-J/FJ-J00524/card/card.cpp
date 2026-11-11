#include<bits/stdc++.h>
using namespace std;

int n,m;
int c[500005];
int x[300005];
int t[500005];
int b;

void ADD(int pai){
	
	
	for(b=n;t[b]==0;b--){}
	if(t[1]==-1){t[1]=pai; return;}
	else{

		for(int index=1;index<=b;index++){

			if(t[index]==pai){

				for(int j=index;j<=b+1;j++){t[j]=0;}
				t[index]=pai;
				return;

			}else t[b+1]=pai;
		}

	}
	return;
}
void check(){
/*	for(int i=1;i<b;i++){
		cout<<t[i]<<' ';
	}*/
	for(int i=1;i<=n;i++){
		if(t[i]!=0){
			x[t[i]]++;
		}
	}
	//cout<<endl;
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		t[1]=-1;
		for(int j=i;j<=n;j++){
			 ADD(c[j]);
		}
		check();
	}
	for(int i=1;i<=m;i++){
		printf("%d ",x[i]);
	}

	return 0;
}

