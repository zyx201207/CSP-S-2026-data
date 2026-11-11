//个人报名 刘盾 GZ-S00442
#include<bits/stdc++.h>
using namespace std;
int n,m,temp,ct=1,maxs,t;
vector<int> a;
int c[500005];
void f(int i,int o,bool b){
	for(int j=i;j<o;j++){
		if(i<o&&b==1){
			f(j+1,o,1);
			b=0;
		}
		if((t-(temp-a[j]))<0)break;
		if(a[j]<=temp&&c[j]!=1){
			c[j]=1;
			t=t-(temp-a[j]);
			ct++;
		}
	}	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
	}
	for(int i=1;i<n;i++){
		sort(a.begin(),a.end());
		t=m;
		temp=a[i];
		f(0,i,1);
		for(int j=0;j<n;j++)c[j]=0;
		maxs=maxs<ct?maxs=ct:maxs;
		ct=1;
	}
	printf("%d",maxs);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

