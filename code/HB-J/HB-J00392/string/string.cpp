#include<bits/stdc++.h>
using namespace std;
struct zf{
	long long m;
	char s;
};
int n=0;
zf a[200010];
long long g=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
	}for(int i=1,j=n;i<j;){
		int mi;
		if(a[i].m>a[j].m) mi=a[j].m;
		else mi=a[i].m;
		if(a[i].s!=a[j].s){
			g+=mi;
		}a[i].m-=mi;
		a[j].m-=mi;
		if(a[j].m==0) j--;
		if(a[i].m==0) i++;
	}cout<<g;
	return 0;
}
