//GZ-J00568 遵义市第四初级中学 罗俊毅 
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a];
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a,cmp);
	int mmax=0;
	for(int i=0;i<a-1;i++){
		if(c[i]<mmax)break;
		for(int j=i+1;j<a-1;j++){
			if(c[j]<mmax)break;
			int o=c[i]&c[j];
			if(o>mmax)mmax=o;
		}
	}
	printf("%d",mmax);
	return 0;
}
