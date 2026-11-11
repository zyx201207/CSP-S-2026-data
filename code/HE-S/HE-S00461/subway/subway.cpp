#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k1,k2,q1,q2;
	cin>>c>>n>>m>>d>>q;
	int a[m+2],k11[m+2],k22[m+2];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	cin>>k1;
	for(int i=0;i<2*k1;i++){
		cin>>k11[i];
	}
	cin>>k1;
	for(int i=0;i<2*k2;i++){
		cin>>k22[i];
	}
	cin>>q1>>q2;
	if(abs(q1-q2)==1){
		cout<<k1[min(q1,q2)]+k2[min(q1,q2)]+k2[max(q1,q2)]+k1[max(q1,q2)];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);//CSP
} 
