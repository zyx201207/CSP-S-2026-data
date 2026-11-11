#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,i,j=1,t,h=2,l1=0,l2,f=0,max=2147483647,nt;
	cin >> n >> m;
	nt=n;
	int a[n+5],l[m+1];
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	while(nt!=1){
		if(nt%2==0){
			nt/=2;
			f++;
		}else{
			nt=(nt-1)/2;
			f++;
		}
	}
	for(i=1;i<=f;i++){
		j=j*2;
	}
	for(i=1;i<=n;i++){
		t=j-a[i];
		if(t<max&&t>=0){
			l[h]=l[h-1];
			max=t;
			l[h-1]=a[i];
			h++;
		}
	}
	cout << l[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
