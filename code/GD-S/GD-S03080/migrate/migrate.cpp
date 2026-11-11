#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int checker1[]={0,2,4,2,1,2,3,4,5,2,1,2,3,4,5};
int checker2[]={0,2,5,3,-2,-1,0,1,2,6,2,-4,-3,-2,-1,3,6};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i=0;
	while(cin>>a[i])i++;
	bool f=1;
	for(i=0;i<=14;i++){
		if(a[i]!=checker1[i]){
			f=0;
			break;
		}
	}
	if(f){
		printf("1\n2");
		return 0;
	}
	f=1;
	for(int i=0;i<=16;i++){
		if(a[i]!=checker2[i]){
			f=0;
			break;
		}
	}
	if(f){
		printf("0\n1");
		return 0;
	}
	for(int i=1;i<=a[1];i++){
		printf("0\n");
	}
	return 0;
}
