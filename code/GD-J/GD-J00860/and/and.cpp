#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long n,m;
const long long q=1e+6;
long long a[q][35];
long long b[35];//每一个数位上1的总个数 
long long result=0;
int e=0;//二进制最高位 
void achange(long long x){
	int w=1;
	while(a[x][0]>0){
		a[x][w]=a[x][0]%2;
		a[x][0]/=2;
		if(a[x][w]==1)b[w]++;
		w++;
	}
	w--;
	a[x][0]=1;
	e=max(e,w);//更新二进制最高位 
}//函数->二进制转换
long long cifang(int x){
	if(x==0)return 1;
	return cifang(x-1)*2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	/*-----*/
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i][0];
		achange(i);
	}
	/*所有数字完成二进制转换，状态可用*/ 
	long long w=cifang(e-1);
	for(int i=e;i>=1;i--){
		for(long long j=1;j<=n;j++){
			if(a[j][i]==1&&a[j][0]==0){
				b[i]--;//如果数字不能使用且该数该数位是1，该数位上可用的1减少一个 
			}
			if(a[j][i]==0&&b[i]>=m){
				a[j][0]=0;//如果该数位上的1足够多但该数该数位是0，数字不再使用 
			}
		}
		if(b[i]>=m){
			result+=w;//如果该数位上的1足够多，结果的该位为1 
		}
		w/=2;
	}
	cout<<result;
	return 0;
	/*-----*/
	fclose(stdin);
	fclose(stdout);	
} 
