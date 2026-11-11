#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
#define LL long long
LL n,l,k,lx=1,rx,c,al[N][3];
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>l;
		cin>>a;
		k+=l;
		al[i][1]=int(a);
		al[i][2]=l;
	}
	while(lx!=n-rx){
		if(al[lx][1]!=al[n-rx][1]){
			if(al[lx][2]>=al[n-rx][2]){
				c+=al[n-rx][2];
				al[lx][2]-=al[n-rx][2];
				rx++;
			}
			else if(al[lx][2]<al[n-rx][2]){
				c+=al[lx][2];
				al[n-rx][2]-=al[lx][2];
				lx++;
			} 
		}
		else{
			if(al[lx][2]>=al[n-rx][2]){
				al[lx][2]-=al[n-rx][2];
				rx++;
			}
			else if(al[lx][2]<al[n-rx][2]){
				al[n-rx][2]-=al[lx][2];
				lx++;
			} 
		}
	}
	cout<<c;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
