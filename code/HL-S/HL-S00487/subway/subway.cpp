#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
inline int ir(){
	int temp = 0 , t = 1;
	char ch = getchar();
	while(ch<'0' || ch>'9'){
		if (ch=='-') t=-1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		temp = temp*10 + (ch-'0');
		ch = getchar();
	}
	return temp*t;
}
int c , n , m , d , q , w[500002];//none   subway route   subway stop   subway r^s   plan   w
bool sub[502][500002]={{0}};//subway map(route ^ stop)
int subtim[502][500002]={{0}};//subway time(route ^ stop)
int planfrom , planto;//plan: constant: from    destination
int subpos[500002]={-1};//subway been
long long df(int stop,int pst){
	for(int i=1;i<=n;i++){
	if(sub[i][stop]) df
	}
}
int main(){
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	c=ir();
	n=ir();
	m=ir();
	d=ir();
	q=ir();
	for(int i=1;i<=m;i++) w[m]=ir();
	int conmeet , constop;//constant r^s   constant stop
	for(int i=1;i<=n;i++){
		conmeet=ir();
		for(int j=1;j<=conmeet;j++){
			constop = ir();
			sub[i][constop] = 1;
			subtim[i][constop] = ir();
		}
	}
	for(int pla=1;pla<=q;pla++){
		planfrom=ir();
		planto=ir();
		cout<<df(planfrom , 0)+w[planfrom]+w[planto]<<"\n";
	}
	return 0;
}