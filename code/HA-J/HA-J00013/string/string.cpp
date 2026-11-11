#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
//int cut[500000];//400000
//int cnt;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long leni=0,lenj=0,tli=0,tlj=0;//leni zong   tli just now
	int ti=0,tj=n+1;
	while(ti<tj){
		if(tli>=leni){
			leni+=a[++ti];
		}
		if(tlj>=lenj){
			lenj+=a[--tj];
		}
		if(ti>=tj)break;
		if(leni-tli<lenj-tlj){
			if(c[ti]!=c[tj]){
				ans+=leni-tli;
			}
			tli+=(leni-tli);
			tlj+=(leni-tli);
		}
		else{
			if(c[ti]!=c[tj]){
				ans+=lenj-tlj;
			}
			tli+=(lenj-tlj);
			tlj+=(lenj-tlj);
		}
	}
	cout<<ans;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
