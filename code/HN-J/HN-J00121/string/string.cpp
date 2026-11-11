#include <iostream>
using namespace std;
#define MAXN 20005
int n,a[MAXN]={},bi=0,en=0;
long long ans,long1;
char b[MAXN]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		long1+=a[i];
	}
	en=n-1;
	while(bi+en<n&&bi<en){
//		cout<<bi<<' '<<en<<endl;
		if(b[bi]!=b[en]){
			if(a[bi]>a[en]){
//				cout<<"a[bi]>a[en]\n";
				ans+=a[en];
				a[bi]-=a[en];
				bi--;
//				n++; 
			}else if(a[bi]==a[en]){
				ans+=a[bi];
			}else{
//				cout<<"a[bi]<a[en]\n";
				ans+=a[bi];
				a[bi]-=a[en];
				en++;
//				n++;
			}
		}
		bi++;
		en--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5
3 a
2 b
3 c
1 b
2 c
aaabbcccbcc

*/
