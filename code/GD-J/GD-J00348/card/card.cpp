#include<bits/stdc++.h>
using namespace std;
int ri(){
	int ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
int a[500010],la[300010],ops[500010];
int ans[300010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=ri(),m=ri();
	
	for(int i=1;i<=n;i++){
		ops[i]=ri();
		a[i]=i;
		if(la[ops[i]]!=0)	a[la[ops[i]]]=i;
		la[ops[i]]=i;
	}
	//for(int i=1;i<=n;i++)	cout<<a[i]<<" ";
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		//cout<<i<<endl;
		bool f[300010]={0};
		for(int j=i;j<=n;){
			//cout<<j<<" "<<ops[j]<<" "<<f[ops[j]]<<" to ";
			if(!f[ops[j]])	ans[ops[j]]++,f[ops[j]]=1;
			if(a[j]!=j)	j=a[j];
			else	j++;
			//cout<<j<<" "<<ops[j]<<endl;
			//for(int i=1;i<=m;i++){
			//	printf("%d ",ans[i]);
			//}
			//cout<<endl;		
		}
			
		//cout<<endl<<endl;
		
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
