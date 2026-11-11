#include<bits/stdc++.h>
using namespace std;
int a,s,d,z[1000001],z1[1000001],x[1000001];
int x1[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&a,&s);
	for(int q=1;q<=a;q++){
		scanf("%d",&z[q]);
	}
	for(int q=1;q<=a;q++){
		int p=0;
		for(int w=q;w<=a;w++){
			if(x1[z[w]]>p)x1[z[w]]=0;
			if(x1[z[w]]!=0){
				p=x1[z[w]];
			}else{
				p++;
				x[p]=z[w];
				x1[z[w]]=p;
			}
		}
		for(int w=1;w<=p;w++){
			z1[x[w]]++;
		}
		for(int w=1;w<=a;w++)x1[w]=0;
	}
	for(int q=1;q<=s;q++){
		cout<<z1[q]<<' ';
	}
	return 0;
}/*
4 3
1 2 1 3*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
