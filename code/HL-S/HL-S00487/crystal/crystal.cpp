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
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	long long n = ir() , m = ir() , ans=1;//n m answer
	int num[500001];
	for(int i=0;i<n;i++) num[i]=ir();
	int ins ,cons;// max insert    constant number
	for(int i=0;i<n;i++){
		ins = i;
		for(int j=i;j<n;j++) if(num[j]>num[ins]) ins = j;
		cons=num[i];
		num[i]=num[ins];
		num[ins]=cons;
	}// reserve = false
	long long conans , conm , connum; //constant: answer m num
	for(int i=n;i>=0;i--){
		connum = num[i];
		conm = m;
		conans = 1;
		for(int j=i+1;j<n;j++){
			if(connum-num[j] == conm){
				conans+=1;
				break;
			}else if(connum-num[j] > conm) break;
			conm-=connum-num[j];
			conans+=1;
		}
		if(conans > ans) ans = conans;
	}
	cout<<ans;
	return 0;
}