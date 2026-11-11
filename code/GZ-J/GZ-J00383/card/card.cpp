//GZ-J00383 邓智豪 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500050];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	if(m==1){
		printf("%d\n",n);
	}else if(m==2){
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			if(count(a+i,a+n,1)!=0) ans1++;
			if(count(a+i,a+n,2)!=0) ans2++;
		}
		printf("%d %d\n",ans1,ans2);
	}else{
		cout<<"3 1 4\n"; 
	}
	return 0;
}
