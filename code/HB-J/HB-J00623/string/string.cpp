#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,k,cs=0,val=0;
int a[200005],pos[200005];
char s[200005];
signed main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		pos[i]=pos[i-1]+a[i];
	}
	int l=1,r=pos[n],posl=1,posr=n;
	while(l<=r&&l>0&&r<=n){
		val=0;
		if(pos[posl]+1-l<r-pos[posr-1]){
			int v2=pos[posl]+1-l;
			l=pos[posl]+1;
			r-=v2;
			posl++;
			val=v2;
		}	
		else if(pos[posl]+1-l>r-pos[posr-1]){
			int v2=r-pos[posr-1];
			l+=r-pos[posr-1];
			r=pos[posr-1];
			posr--;
			val=v2;
		}	
		else if(pos[posl]+1-l==r-pos[posr-1]){
			int v2=r-pos[posr-1];
			l=pos[posl]+1;
			r=pos[posr-1];
			posl++;
			posr--;
			val=v2;
		}	
		//if(l>r) break;
		char v1,v2;
		if(pos[posl-1]+1==l) v1=s[posl-1];
		else v1=s[posl];
		if(pos[posr]==r) v2=s[posr+1];
		else v2=s[posr];
		//printf("one times posl%lld posr%lld l%lld r%lld value1%c,value2%c,val%lld\n",posl,posr,l,r,v1,v2,val);
		if(v1!=v2){
			cs+=val;
		}
	}
	cout<<cs;
    return 0;
}
/*
 
*/
