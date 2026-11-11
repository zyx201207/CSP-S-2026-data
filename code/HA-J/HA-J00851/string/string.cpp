#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char u;
}a[200005];

long long ans;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].u;}
	int l=1,r=n;

	a[0].num=0;
	while(l<r){

		if(a[l].u!=a[r].u){
			if(r-l==1){ans+=min(a[r].num,a[l].num);break;}
			
			else {ans+=min(a[r].num,a[l].num);}
		}
		if(a[l].num>a[r].num){a[l].num-=a[r].num;	a[r].num=0;		r--;}
		else {a[r].num-=a[l].num;	a[l].num=0;		l++;}
		
	}
	long long p=0;


	
	cout<<ans+p;
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
